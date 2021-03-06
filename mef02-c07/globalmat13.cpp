#include "globalmat13.h"

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

void globalmat13 (cmalla2d01 *m, cgauss02 *g, double deltat, double r, cdiffusion2d *diff, SparseMatrix<double> &a) {

    /* MATVEC13: Operador de Black-Scholes. Matriz del sistema de ecuaciones.
                 Matrices huecas.
                 Se calcula una sola vez.

       Entradas:
       - m: 
       - g: 
       - deltat: paso de tiempo (real, positivo).
       - f:      coeficiente de reacción.

    */

    celem2d *ef;
    map <int, celem2d *> :: iterator ielt;
    std::vector<int> indices (3, 0);

    Matrix3d aelt, aelt01, aelt02;

//    double deltatau = -deltat;
    double deltatau = deltat;

    /* ----------------------------------------------------------------- */
    // Bucle sobre los elementos.

    a.setZero ();
    for (ielt=m->eltos.begin(); ielt!=m->eltos.end(); ielt++) {
        ef = ielt->second;

        aelt = Matrix3d::Zero ();
        aelt01 = Matrix3d::Zero ();
        aelt02 = Matrix3d::Zero ();

        mat3d11 (ef, g, diff, aelt01);          // Difusión.
        mat3d12 (ef, g, aelt02);                // Masa.

        aelt = (1.0 + deltatau * r) * aelt02 + deltatau * aelt01;
//        aelt = aelt01;

        indices [0] = ef->nodos[0]->id;
        indices [1] = ef->nodos[1]->id;
        indices [2] = ef->nodos[2]->id;

        ensamb30 (indices, aelt, a);
    }
}

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

