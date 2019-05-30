#include "optioneuro00.h"

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

void optioneuro00 (vector <cmalla2d01 *> mallas, int level, cmalla2d01 *m, cgauss02 *g, 
                   cdataprob dprob, cdatamesh dmesh, cdatanum dnum,
                   map <int, celem2d *> geltos, map <int, cnodo2d *> gnodos, map <int, carista *> garistas, 
                   cbs *bs, cmark *fmark,
                   VectorXd &uold, cdiffusion2d *diff, cconvection2d *velocity01, cconvection2d *velocity02) {

    /* SOLVER03: Resolución del problema lineal (M = V).
                 No hay refinamiento de mallado a lo largo del tiempo.
 
    Entradas:
    - m: (puntero a) malla actual.
    - g: 
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

    SparseMatrix <double> a (m->nsom,m->nsom);
    globalmat14 (m, g, dnum.caracdeltat, dprob.r, dprob.R, dprob.hinf, diff, a);
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
    VectorXd uk = VectorXd::Zero (m->nsom);
    VectorXd v = VectorXd::Zero (m->nsom);

    // Bucle temporal.

    cout << endl;
    printf ("    Time       Real  \n");
    printf ("    Step       Time  \n\n");

    int n = 0;
    double t = dprob.tfin;
    double tau = dprob.tini;
    double minimo_u;

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
        globalvec12 (m, g, uold, bc);

        // Vector segundo miembro

        bk = VectorXd::Zero (m->nsom);
        uk = VectorXd::Zero (m->nsom);
        for (int i=0; i<m->nsom; i++) {
            uk[i] = -dprob.hinf * m->nodos[i]->y * positive (v(i));
        }
        globalvec13 (m, g, uk, bk);

        // Resolución del sistema lineal.

        b = dnum.caracdeltat * (bf + bk) + bc;
        dirichlet22 (m, uk, uold, dnum.caracdeltat, dprob.f, b);
        u = solver.solve (b);           

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

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

