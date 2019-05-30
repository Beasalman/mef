#include "elmat1d2gdl02.h"

/* ----------------------------------------------------------------- */

void elmat1d2gdl02 (celem1d *ef, const cgauss1d *g, Matrix2d &a) {

    /* ELMAT1D2GDL02: Matriz elemental
                      Problema 1-D, un grado de libertad por nodo.
                      Término de reacción: Int [u v dx]
      
    Entradas:
    - ef: elemento actual.
    - g:  nodos y pesos de integración.
     
    Entrada/salida:
    - a: matriz elemental.
    */

    MatrixXd p (1,2);

    for (int k=0; k<g->n; k++) {
        p (0) = 0.5 * (1.0 - g->x [k]);
        p (1) = 0.5 * (1.0 + g->x [k]);
        a += g->peso [k] * p.transpose() * p;
    }

    // *********************************************************************************************
    //cout << " [ELMAT1D2GDL02]       Elemento: " << ef->id << "        Jacobiano: " << ef->jac << endl;
    //cout << " [ELMAT1D2GDL02]       Matriz elemental: " << a << endl;
    // *********************************************************************************************

    a = ef->jac * a;
}

/* ----------------------------------------------------------------- */

