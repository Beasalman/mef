#include "optionamer01.h"

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

void optionamer01 (vector <cmalla2d01 *> mallas, int level, cmalla2d01 *m, cgauss02 *g2, cgauss1d *g1,
                   cdataprob dprob, cdatamesh dmesh, cdatanum dnum,
                   map <int, celem2d *> geltos, map <int, cnodo2d *> gnodos, map <int, carista *> garistas, cbs *bs, 
                   cdir1d *dir1d, cpayoff *payoff, cmark *fmark,
                   VectorXd &vhold, cdiffusion2d *diff, cconvection2d *velocity) {

    /* OPTIONAMER01: Opción americana 2D.
                     Sin refinamiento de mallado a lo largo del tiempo.
 
    Entradas:
    - m: (puntero a) malla actual.
    - g: 
    - dmesh: 
    */

    int j, iter1;
    double errj;
    double beta1 = 10000.0;       // Parámetros del método ALAS.
    double niter1 = 500;          // Habría que llevarlos a DNUM.
    double eps1 = 0.001;

    cnodo1d *nod1;
    cnodo2d *nod, *nodb, *nodc;
    celem2d *ef, *efc;
    cfrontera2d *fr;
    map <int, celem2d*> :: iterator ielt;
    Vector2d y, z;
    map <double, double> w1;

    // ----------------------------------------------------------------------------
    // Cálculo de los puntos desplazados sobre la malla 2D. 
    // Los asociamos a cada elemento de la malla.  Almacenamos sus coordenadas baricéntricas.

    for (ielt=m->eltos.begin(); ielt!=m->eltos.end(); ielt++) {
        ef = ielt->second;
        for (int i=0; i<g2->n; i++) {
            y (0) = g2->x [i];
            y (1) = g2->y [i];
            z = ef->ck * y + ef->dk;
            nodc = new cnodo2d (-1, 0., 0.);
            nodc = carac02 (z, dnum.caracdeltat, 10, velocity, m);

            efc = localiza01 (mallas, level, nodc);
            ef->eltosdesplazados.push_back (efc);

            nodb = new cnodo2d (-1, 0., 0.);
            baric01 (efc, nodc, nodb);
            ef->nodosdesplazados.push_back (nodb);
        }
    }

    // ----------------------------------------------------------------------------
    // Cálculo de los puntos desplazados de la frontera 1. Almacenamos sus coordenadas baricéntricas.

    /*
    fr = m->fronteras [1];
    for (int i=0; i<fr->nodos.size(); i++) {
        nod = fr->nodos [i];
        z (0) = nod->x;
        z (1) = nod->y;
        nodc = new cnodo2d (-1, 0., 0.);
        nodc = carac02 (z, dnum.caracdeltat, 10, velocity, m);

        efc = localiza01 (mallas, level, nodc);
        nod->eltodesplazado = efc;

        nodb = new cnodo2d (-1, 0., 0.);
        baric01 (efc, nodc, nodb);
        nod->nododesplazado = nodb;
    }
    */

    // ----------------------------------------------------------------------------
    // Matriz (hueca) del sistema de ecuaciones.

    SparseMatrix <double> a (m->nsom,m->nsom);
    globalmat13 (m, g2, dnum.caracdeltat, dprob.f, diff, a);
    dirichlet23 (m, a);
    a.makeCompressed ();

    SparseLU <SparseMatrix <double> > solver;
//    SparseQR <SparseMatrix <double> > solver;
//    BiCGSTAB <SparseMatrix <double> > solver;
    solver.compute (a);

    // ----------------------------------------------------------------------------
    // Vectores: características, punto fijo y vector global.

    VectorXd bc (m->nsom);
    VectorXd bk (m->nsom);
    VectorXd b (m->nsom);

    // Vectores.

    VectorXd v = VectorXd::Zero (m->nsom);          // Solución del pb. sin riesgo 1D, extendido a la malla 2D.
    VectorXd vh (m->nsom);                          // Solución del pb. con riesgo.
    VectorXd u (m->nsom);                           // u = vh - v (CVA).

    VectorXd vhk = VectorXd::Zero (m->nsom);
    VectorXd vhant = VectorXd::Zero (m->nsom);
//    VectorXd vhold = VectorXd::Zero (m->nsom);
//    VectorXd ua = VectorXd::Zero (m->nsom);

    // Obstáculo del problema 2D.

    VectorXd psi = VectorXd (m->nsom);
    for (int i=0; i<m->nsom; i++) {
        psi (i) = (*payoff)(m->nodos[i]->x);
    }

    // -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
    // Malla del problema 1D.

    cmalla1d *p = meshgen2d1d (m);

    // Vectores y matriz del problema 1D.

    VectorXd b1 = VectorXd::Zero (p->nsom);
    VectorXd u1 = VectorXd (p->nsom);
    VectorXd psi1 = VectorXd (p->nsom);
    Vector2d vdir1;
    SparseMatrix <double> a1 (p->nsom,p->nsom);

    globalmat02 (p, g1, dprob, dnum, a1);
    dirichlet00 (p, a1);
    
    // Obstáculo del problema 1D.

    for (int i=0; i<p->nsom; i++) {
        psi1 (i) = (*payoff)(p->nodos[i]->x);
    }

    // Nodos y elementos de los puntos desplazados sobre las curvas características.

    cvelocity1d *velo1d = new cvelocity1d (dprob.sigmax, dprob.r, dprob.q);
    ccurve *cc = NULL;
    cc = new ccurve01 (velo1d, dnum.caracdeltat, p->nodos[0]->x, p->nodos.back()->x);

    vector <double> caracpoint;
    vector <celem1d *> caracelt;
    carac1d (p, g1, velo1d, cc, caracpoint, caracelt);

    // -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
    // Bucle temporal.

    cout << endl;
    printf ("    Time       Real         Solver           Solver     \n");
    printf ("    Step       Time          Error          Iter. Nr. \n\n");

    int n = 0;
    int jmax = 50;                       // Pasarlo a DNUM.
    double tol_err = 1.e-4;              // Pasarlo a DNUM.
    double t = dprob.tfin;
    double tau = dprob.tini;
//    ua = util03 (m, analyt, t);

    printf ("   %5d", n);
    printf ("   %8.3f", t);
    printf ("      %12s", "");
    printf ("       %5s", "");
    //printf ("             %12.8e", error02 (uold, ua));
    printf ("\n");

    int itp = 0;
    for (int n=0; n<dnum.caracniter; n++) {
        t -= dnum.caracdeltat;
        tau += dnum.caracdeltat;
        printf ("   %5d", n+1);
        printf ("   %8.3f", t);

        // ------------------------------------------------------------------------
        // Valor de la opción sin riesgo: resolución del problema 1D con obstáculo.
        // Vector del término de características (1D)

        b1.setZero ();
        globalvec02 (p, g1, caracpoint, caracelt, u1, b1);          // *** Cuánto vale inicialmente u1 ?

        // Condiciones de contorno y resolución del sistema.

        vdir1 = (*dir1d) (tau);
        dirichlet00 (p, b1, vdir1);
        iter1 = 0;

        util02 (psi1, u1);                                     // En cada paso, partimos del obstáculo (???).
        alas (a1, b1, psi1, u1, beta1, eps1, niter1, iter1);

        // Salvaguarda en un diccionario y extensión a la malla 2D.

        for (int i=0; i<p->nsom; i++) {
            nod1 = p->nodos [i];
            w1 [nod1->x] = u1 [i];
        }
        for (int i=0; i<m->nsom; i++) {
            nod = m->nodos [i];
            v (i) = w1 [nod->x];
        }

        // ------------------------------------------------------------------------
        // Problema 2D.
        // Vector del término de características (2D).

        bc = VectorXd::Zero (m->nsom);
        globalvec12 (m, g2, vhold, bc);

        // Bucle de punto fijo.

        j = 0;
        errj = 1000.0;
        util02 (v, vhant);

        while ((j < jmax) && (errj > tol_err)) {
            j += 1;

            // Vector segundo miembro.

            bk.setZero ();
            vhk.setZero ();
            for (int i=0; i<m->nsom; i++) {
                vhk[i] = dprob.hinf * m->nodos[i]->y * positive (vhant(i));
            }
            globalvec13 (m, g2, vhk, bk);

           // Resolución del sistema lineal.

            b = -dnum.caracdeltat * bk + bc;
            dirichlet23 (m, v, vhant, vhold, dnum.caracdeltat, dprob.f, dprob.hinf, payoff, b);
            alas (a, b, psi, vh, beta1, eps1, niter1, iter1);
            errj = error02 (vh, vhant);
            util02 (vh, vhant);
        }

        u = vh - v;
        printf ("     %12.8e", 0.0);
        printf ("      %5ld", 0L);

        // Reactualización y salvaguarda de resultados.

        if (n % dnum.nitp == 0) {
            itp += 1;
            fprint11 (level, itp, u);                    // Aproximación numérica.
        }
        cout << endl;

        // ----------------------------------------------------------------------------
        // Refinamiento de la malla y prolongación de magnitudes.

        /*
        if ((n+1) % dnum.nitp == 0) {

            // ***************************************************************************
            //cout << endl;
            //cout << " [SOLVER03]    m->nsom = " << m->nsom << endl;
            //cout << " [SOLVER03]    mallas.size() = " << mallas.size() << endl;
            // ***************************************************************************

            meshref02 (mallas, level, g, dprob, dmesh, dnum, geltos, gnodos, garistas, fmark, uold, u,
                       a, velocity, diff);

            // ***************************************************************************
            //cout << " [SOLVER03] Hemos salido de MESHREF02" << endl;
            //cout << " [SOLVER03]    mallas.size() = " << mallas.size() << endl;
            // ***************************************************************************

            m = mallas.back ();
            bc.resize (m->nsom);
            b.resize (m->nsom);
            ua.resize (m->nsom);
            v.resize (m->nsom);

            // ***************************************************************************
            //cout << " [SOLVER03] Hemos redimensionado los vectores" << endl;
            // ***************************************************************************

            solver.compute (a);

            // ***************************************************************************
            //cout << " [SOLVER03] Hemos recalculado SOLVER" << endl;
            //cout << " [SOLVER03]    m->nsom = " << m->nsom << endl;
            //cout << endl;
            // ***************************************************************************

        }
        */
    }
}

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

