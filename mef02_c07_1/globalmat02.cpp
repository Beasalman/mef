#include "globalmat02.h"

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

void globalmat02 (cmalla1d *m, cgauss1d *g, cdataprob dprob, cdatanum dnum, double sigma, SparseMatrix <double> &a) {

    /* GLOBALMAT02: Construcción de la matriz global.
                    Almacenamiento en matriz hueca.
                    Problema unidimensional.
                    Matrices elementales 2 x 2 (un grado de libertad por nodo).
    */

    double coef02 = 1.0 + (dprob.r + dprob.lambdaB + dprob.lambdaC)* dnum.caracdeltat;
    double coef03 = 0.5 * sigma  * dnum.caracdeltat;
    celem1d *ef;
    std::vector <int> indices (2);

    Matrix2d aelt, aelt02, aelt03;

    /* ----------------------------------------------------------------- */
    // Bucle sobre los elementos.

    for (int nef=0; nef<m->eltos.size(); nef++) {
        ef = m->eltos [nef];

        // Indices de los nodos.

        for (int k=0; k<ef->nodos.size(); k++) {
            indices [k] = ef->nodos[k]->id;
        }

        // Matrices elementales.

        aelt02 = Matrix2d::Zero ();
        aelt03 = Matrix2d::Zero ();

        elmat1d2gdl02 (ef, g, aelt02);           // Masa.
        elmat1d2gdl03 (ef, g, aelt03);           // Difusión.

        // Ensamblado.

        aelt = coef02 * aelt02 + coef03 * aelt03;
        ensmat (indices, aelt, a);
    }
}

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

