#include "optionamer01.h"

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

void optionamer01 (vector <cmalla2d01 *> mallas, int level, cmalla2d01 *m, cgauss1d *g1, cgauss02 *g2, 
                   cdataprob dprob, cdatamesh dmesh, cdatanum dnum,
                   map <int, celem2d *> geltos, map <int, cnodo2d *> gnodos, map <int, carista *> garistas, 
                   cbs *bs, cdir1d *dir1d, cpayoff *payoff, cmark *fmark,
                   VectorXd &vold, cdiffusion2d *diff, cconvection2d *velocity01, cconvection2d *velocity02) {

    /* OPTIONAMER01: Opción americana 2D.
                     Sin refinamiento de mallado a lo largo del tiempo.
 
    Entradas:
    - m: (puntero a) malla actual.
    - g: 
    - dmesh: 
    */

    int j;
    double errj;
    cnodo2d *nod, *nodb, *nodc;
    celem2d *ef, *efc;
    cfrontera2d *fr;
    map <int, celem2d*> :: iterator ielt;
    Vector2d y, z;

    // ----------------------------------------------------------------------------
    // Cálculo de los puntos desplazados sobre la malla 2D. Almacenamos sus coordenadas baricéntricas.

    for (ielt=m->eltos.begin(); ielt!=m->eltos.end(); ielt++) {
        ef = ielt->second;
        for (int i=0; i<g2->n; i++) {
            y (0) = g2->x [i];
            y (1) = g2->y [i];
            z = ef->ck * y + ef->dk;
            nodc = new cnodo2d (-1, 0., 0.);
            nodc = carac02 (z, dnum.caracdeltat, 10, velocity01, m);

            efc = localiza01 (mallas, level, nodc);
            ef->eltosdesplazados.push_back (efc);

            nodb = new cnodo2d (-1, 0., 0.);
            baric01 (efc, nodc, nodb);
            ef->nodosdesplazados.push_back (nodb);
        }
    }

    // ----------------------------------------------------------------------------
    // Cálculo de los puntos desplazados de la frontera 1. Almacenamos sus coordenadas baricéntricas.

    fr = m->fronteras [1];
    for (int i=0; i<fr->nodos.size(); i++) {
        nod = fr->nodos [i];
        z (0) = nod->x;
        z (1) = nod->y;
        nodc = new cnodo2d (-1, 0., 0.);
        nodc = carac02 (z, dnum.caracdeltat, 10, velocity02, m);

        efc = localiza01 (mallas, level, nodc);
        nod->eltodesplazado = efc;

        nodb = new cnodo2d (-1, 0., 0.);
        baric01 (efc, nodc, nodb);
        nod->nododesplazado = nodb;
    }

    // ----------------------------------------------------------------------------
    // Matriz (hueca) del sistema de ecuaciones.

    SparseMatrix <double, ColMajor> a (m->nsom,m->nsom);
    globalmat13 (m, g2, dnum.caracdeltat, dprob.f, diff, a);
    dirichlet23 (m, a);
    a.makeCompressed ();

    // ----------------------------------------------------------------------------
    // Vectores: características, punto fijo y vector global.

    VectorXd bc (m->nsom);
    VectorXd bk (m->nsom);
    VectorXd b (m->nsom);

    // Vectores.

    VectorXd v = VectorXd::Zero (m->nsom);          // Solución del pb. con riesgo.
    VectorXd v2 (m->nsom);                          // Solución del pb. sin riesgo 1D, extendido a la malla 2D.
    VectorXd u (m->nsom);                           // u = v - v2 (CVA).

    VectorXd vk = VectorXd::Zero (m->nsom);
    VectorXd vant = VectorXd::Zero (m->nsom);

    // Obstáculo del problema 2D.

    VectorXd psi = VectorXd (m->nsom);
    for (int i=0; i<m->nsom; i++) {
        psi (i) = (*payoff)(m->nodos[i]->x);
    }
    fprint20 (level, psi);

    // -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
    // Malla del problema 1D.

    cmalla1d *p = meshgen2d1d (m);

    // Vectores y matriz del problema 1D.

    VectorXd b1 = VectorXd::Zero (p->nsom);
    VectorXd v1 = VectorXd (p->nsom);
    VectorXd psi1 = VectorXd (p->nsom);
    Vector2d vdir1;
    SparseMatrix <double> a1 (p->nsom,p->nsom);

    globalmat02 (p, g1, dprob, dnum, a1);
    dirichlet00 (p, a1);

    // Obstáculo del problema 1D.

    double obs1;
    for (int i=0; i<p->nsom; i++) {
        obs1 = (*payoff)(p->nodos[i]->x);
        psi1 (i) = obs1;
        v1 (i) = obs1;
    }

    // Nodos y elementos de los puntos desplazados sobre las curvas características.

    cvelocity1d *velo1d = new cvelocity1d (dprob.sigmax, dprob.r, dprob.q);
    ccurve *cc = NULL;
    cc = new ccurve01 (velo1d, dnum.caracdeltat, p->nodos[0]->x, p->nodos.back()->x);

    vector <double> caracpoint;
    vector <celem1d *> caracelt;
    carac1d (p, g1, velo1d, cc, caracpoint, caracelt);

    // Otras variables del problema 1D.

    int iter1;
    int niter1 = 500;
    double beta1 = 10000.0;
    double eps1 = 0.001;
    cnodo1d *nod1;
    map <double, double> w1;

    // -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
    // Bucle temporal.

    cout << endl;
    printf ("    Time       Real         Solver           Solver     \n");
    printf ("    Step       Time          Error          Iter. Nr. \n\n");

    int n = 0;
    double t = dprob.tfin;
    double tau = dprob.tini;

    printf ("   %5d", n);
    printf ("   %8.3f", t);
    printf ("      %12s", "");
    printf ("       %5s", "");
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
        globalvec02 (p, g1, caracpoint, caracelt, v1, b1);

        // Condiciones de contorno y resolución del sistema.

        vdir1 = (*dir1d) (tau);
        dirichlet00 (p, b1, vdir1);
        iter1 = 0;

//        util02 (psi1, v1);                                     // En cada paso, partimos del obstáculo (???).
        alas (a1, b1, psi1, v1, beta1, eps1, niter1, iter1);

        // ********************************************************************
        cout << endl;
        cout << " PROBLEMA 1D: " << endl;
        for (int i=0; i<v1.size(); i++) {
            cout << "       i: " << i << "       v1-psi1: " << v1 (i) - psi1 (i) << endl;
        }
        cout << endl;
        // ********************************************************************

        // Salvaguarda en un diccionario y extensión a la malla 2D.

        for (int i=0; i<p->nsom; i++) {
            nod1 = p->nodos [i];
            w1 [nod1->x] = v1 [i];
        }
        for (int i=0; i<m->nsom; i++) {
            nod = m->nodos [i];
            v2 (i) = w1 [nod->x];
        }

        // ------------------------------------------------------------------------
        // Problema 2D.
        // Vector del término de características (2D).

        bc = VectorXd::Zero (m->nsom);
        globalvec12 (m, g2, vold, bc);

        // Bucle de punto fijo.

        j = 0;
        errj = 1.0 + dnum.pfemax;
        util02 (v, vant);

        while ((j < dnum.pfniter) && (errj > dnum.pfemax)) {
            j += 1;

            // Vector segundo miembro.

            bk.setZero ();
            vk.setZero ();
            for (int i=0; i<m->nsom; i++) {
                vk (i) = dprob.hinf * m->nodos[i]->y * positive (vant (i));
            }
            globalvec13 (m, g2, vk, bk);

           // Resolución del sistema lineal.

            b = bc - dnum.caracdeltat * bk;
            dirichlet23 (m, v, vant, vold, dnum.caracdeltat, dprob.f, dprob.hinf, dprob.sinf, payoff, b);
            alas (a, b, psi, v, beta1, eps1, niter1, iter1);
            errj = error02 (v, vant);
            util02 (v, vant);
        }
        util02 (v, vold);

        // CVA.

        u = v - v2;
        printf ("     %12.8e", 0.0);
        printf ("      %5ld", 0L);

        // ********************************************************************
        cout << " PROBLEMA 2D: " << endl;
        for (int i=0; i<v.size(); i++) {
            cout << "       i: " << i << "       v-psi: " << v (i) - psi (i);
            cout << "      v2-psi: " << v2 (i) - psi (i);
            cout << "       u: " << u (i);
            cout << endl;
        }
        cout << endl;
        // ********************************************************************

        // Reactualización y salvaguarda de resultados.

        if (n % dnum.nitp == 0) {
            itp += 1;
            fprint11 (level, itp, u);                    // Aproximación numérica del CVA.
            fprint18 (level, itp, v);                    // Aproximación numérica del valor con riesgo.
            fprint19 (level, itp, v2);                   // Aproximación numérica del valor sin riesgo.
        }
        cout << endl;







    }







}

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */



/*
//    SparseLU <SparseMatrix <double> > solver;
//    solver.compute (a);

    // ----------------------------------------------------------------------------
    // Vectores: características, punto fijo y vector global.

    VectorXd bc (m->nsom);
    VectorXd bk (m->nsom);
    VectorXd b (m->nsom);

    // Vectores: soluciones numérica y analítica.

    VectorXd u (m->nsom);
    VectorXd uk = VectorXd::Zero (m->nsom);
    VectorXd uant = VectorXd::Zero (m->nsom);
    VectorXd v = VectorXd::Zero (m->nsom);

    // ----------------------------------------------------------------------------
    // Bucle temporal.

    cout << endl;
    printf ("    Time       Real    \n");
    printf ("    Step       Time  \n\n");

    int n = 0;
    double t = dprob.tfin;
    double tau = dprob.tini;

    printf ("   %5d", n);
    printf ("   %8.3f", t);
    printf ("\n");

    int itp = 0;
    for (int n=0; n<dnum.caracniter; n++) {
        t -= dnum.caracdeltat;
        tau += dnum.caracdeltat;
        printf ("   %5d", n+1);
        printf ("   %8.3f", t);

        // Valor de la opción.

        for (int i=0; i<m->nsom; i++) {
            v (i) = (*bs) (m->nodos[i]->x, tau);
        }

        // Vector del término de características.

        bc = VectorXd::Zero (m->nsom);
        globalvec12 (m, g2, uold, bc);

        // Bucle de punto fijo.

        j = 0;
        util02 (uold, uant);
        errj = 1.0 + dnum.pfemax;

        while ((j < dnum.pfniter) && (errj > dnum.pfemax)) {
            j += 1;

            // Vector segundo miembro.

            bk = VectorXd::Zero (m->nsom);
            uk = VectorXd::Zero (m->nsom);
            for (int i=0; i<m->nsom; i++) {
                uk[i] = -dprob.hinf * m->nodos[i]->y * positive (uant(i) + v(i));
            }
            globalvec13 (m, g2, uk, bk);

            // Resolución del sistema lineal.

            b = dnum.caracdeltat * bk + bc;
            dirichlet22 (m, uk, uold, dnum.caracdeltat, dprob.f, b);
            u = solver.solve (b);

            errj = error02 (u, uant);
            util02 (u, uant);
        }

        // Reactualización y salvaguarda de resultados.

        util02 (u, uold);
        if (n % dnum.nitp == 0) {
            itp += 1;
            fprint11 (level, itp, u);                    // Aproximación numérica.
            fprint17 (level, m, v);                      // Solución de BS.
        }
        cout << endl;
    }
}
*/

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

