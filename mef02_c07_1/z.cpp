#include "solver03.h"

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

void solver03 (vector <cmalla2d01 *> mallas, int level, cmalla2d01 *m, cgauss02 *g, cdataprob dprob, cdatamesh dmesh, cdatanum dnum,
               map <int, celem2d *> geltos, map <int, cnodo2d *> gnodos, map <int, carista *> garistas, cmark *fmark,
               VectorXd &uold, cdiffusion2d *diff, cconvection2d *velocity, csecond *sec, canalitica2d *analyt) {

    /* SOLVER03: Resolución del problema.
                 Refinamiento de mallado a lo largo del tiempo.
 
    Entradas:
    - m: (puntero a) malla actual.
    - g: 
    - dmesh: 
    - sec: 
    */

    cnodo2d *nod, *nodb, *nodc;
    celem2d *ef, *efc;
    cfrontera2d *fr;
    map <int, celem2d*> :: iterator ielt;
    Vector2d y, z;

    // ----------------------------------------------------------------------------
    // Cálculo de los puntos desplazados sobre la malla 2D (nodos de integración). Almacenamos sus coordenadas baricéntricas.

    for (ielt=m->eltos.begin(); ielt!=m->eltos.end(); ielt++) {
        ef = ielt->second;
        for (int i=0; i<g->n; i++) {
            y (0) = g->x [i];
            y (1) = g->y [i];
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

    // ----------------------------------------------------------------------------
    // Matriz (hueca) del sistema de ecuaciones.

    SparseMatrix <double> a (m->nsom,m->nsom);
    globalmat13 (m, g, dnum.caracdeltat, dprob.f, diff, a);
//    dirichlet20 (m, a);
    dirichlet22 (m, a);
    a.makeCompressed ();

    SparseLU <SparseMatrix <double> > solver;
    solver.compute (a);

    // ----------------------------------------------------------------------------
    // Vectores: término fuente, características y vector global.

    VectorXd bf (m->nsom);
    VectorXd bc (m->nsom);
    VectorXd bk (m->nsom);
    VectorXd b (m->nsom);

    // Vectores: soluciones numérica y analítica.

    VectorXd u (m->nsom);
    VectorXd ua = VectorXd::Zero (m->nsom);
    VectorXd uk = VectorXd::Zero (m->nsom);
    VectorXd uant = VectorXd::Zero (m->nsom);
    VectorXd v = VectorXd::Zero (m->nsom);

	// Función que proporciona el valor de la opción.

    double d0 = dprob.rr - dprob.f;
    cbs *option;
    if (dprob.opt == 0) {
        option = new cbscall (&dprob.strike, &dprob.f, &dprob.sigmax, &d0, &dprob.sinf);
    } else if (dprob.opt == 1) {
        option = new cbsput (&dprob.strike, &dprob.f, &dprob.sigmax, &d0, &dprob.sinf);
    }

    // Bucle temporal.

    cout << endl;
    printf ("    Time       Real         Solver           Solver               Relative  \n");
    printf ("    Step       Time          Error          Iter. Nr.               Error   \n");
    printf ("                                                              (Analyt/Numer.)   \n\n");

    int n = 0;
    int jmax = 50;
    double tol_err = 1.e-4;
    double t = dprob.tfin;
    double tau = dprob.tini;
    ua = util03 (m, analyt, t);

    printf ("   %5d", n);
    printf ("   %8.3f", t);
    printf ("      %12s", "");
    printf ("       %5s", "");
    printf ("             %12.8e", error02 (uold, ua));
    printf ("\n");

    int itp = 0;
    for (int n=0; n<dnum.caracniter; n++) {
        t -= dnum.caracdeltat;
        tau += dnum.caracdeltat;
        printf ("   %5d", n+1);
        printf ("   %8.3f", t);

        // Valor de la opción.

        for (int i=0; i<m->nsom; i++) {
            v (i) = (*option) (m->nodos[i]->x, tau);
        }

        // Vector término fuente.

        // ************************************************************************
        //cout << endl << "   Segundo miembro: " << (*sec)(0.5, 0.5, t);
        //cout << "   Sol. analítica: " << (*analyt)(0.5, 0.5, t) << endl;
        // ************************************************************************

        bf = VectorXd::Zero (m->nsom);
        //globalvec11 (m, g, sec, bf, t);

        // Vector del término de características.

        bc = VectorXd::Zero (m->nsom);
        globalvec12 (m, g, uold, bc);

//        uant = uold;
        util02 (uold, uant);
        
        int jj = 0;
        double errj = 1000.0;
        while ((jj<jmax) && (errj > tol_err)) {
            jj += 1;

            // Vector segundo miembro

            bk = VectorXd::Zero (m->nsom);
            uk = VectorXd::Zero (m->nsom);
            for (int i=0; i<m->nsom; i++) {
                uk[i] = -dprob.hinf * m->nodos[i]->y * positive (uant(i)+v(i));
            }
            globalvec13 (m, g, uk, bk);

           // Resolución del sistema lineal.

            b = dnum.caracdeltat * (bf + bk) + bc;
            dirichlet22 (m, uk, uold, dnum.caracdeltat, dprob.f, b);
            u = solver.solve (b);
            errj = error02 (u, uant);
            // **********************************************************
            //cout << " [SOLVER03]   Iteración de punto fijo,  jj: " << jj << "   Error: " << errj << endl;
            // **********************************************************
            util02 (u, uant);
        }

        printf ("     %12.8e", 0.0);
        printf ("      %5ld", 0L);
        util02 (u, uold);

        // **********************************************************
        //cout << "   Sol. numérica: " << u(4) << endl;
        // **********************************************************

        // Error relativo con la solución analítica.

        ua = util03 (m, analyt, t);
        printf ("             %12.8e", error02 (u, ua));

        // Reactualización y salvaguarda de resultados.

        util02 (u, uold);

        if (n % dnum.nitp == 0) {
            itp += 1;
            fprint11 (level, itp, u);                    // Aproximación numérica.
            fprint12 (level, itp, m, analyt);            // Solución analítica.
            fprint17 (level, m, v);                      // Solución de BS.
        }
        cout << endl;

        // ----------------------------------------------------------------------------
        // Refinamiento de la malla y prolongación de magnitudes.

        /*
        if ((n+1) % dnum.nitp == 0) {

            // **********************************************************
            cout << " [SOLVER03]    Pasamos a level: " << level+1 << endl;
            // **********************************************************

            level += 1;
            cmalla2d01 *pz = new cmalla2d01 (*m);            // Copia de la malla anterior en una nueva.
            meshref01 (pz, gnodos, geltos, garistas, dmesh.tref1, dmesh.sigma, fmark);       // Refinamiento.
            pz->domain = new cdomain2d (&dmesh.vii, &dmesh.vsd);
            pz->id = level;
            mallas.push_back (pz);
            pz->fprint01 (level);

            // Redimensionamiento de vectores.

            m = mallas [level];

            // **********************************************************
            cout << " [SOLVER03]     m->nsom: " << m->nsom;
            cout << "    pz->nsom: " << pz->nsom << endl;
            // **********************************************************

            a.resize (pz->nsom, pz->nsom);
            bf.resize (pz->nsom);
            bc.resize (pz->nsom);
            b.resize (pz->nsom);
            u.resize (pz->nsom);
            uold.resize (pz->nsom);
            ua.resize (pz->nsom);

            // Prolongación.

            // u
            // uold

            // Cálculo de las nuevas curvas características.


        }
        */
    }
}

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

