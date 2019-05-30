#include "elmat1d2gdl03.h"

/* ----------------------------------------------------------------- */

void elmat1d2gdl03 (celem1d *ef, const cgauss1d *g, Matrix2d &a) {

    /* ELMAT1D2GDL03: Matriz elemental
                      Problema 1-D, un grado de libertad por nodo.
                      Término de difusión: Int [x^2 u' v' dx]
      
    Entradas:
    - ef: elemento actual.
    - g: nodos y pesos de integracion.
     
    Entrada/salida:
    - a: matriz elemental.
    */

    double x;
    MatrixXd dp (1,2);
    Matrix2d dptdp;

    dp (0) = -0.5;
    dp (1) =  0.5;
    dptdp = dp.transpose () * dp;

    for (int i=0; i<g->n; i++) {
        x = ef->xm + ef->jac * g->x[i];
        a += g->peso[i] * x*x * dptdp;
    }
    a = a * (1.0 / ef->jac);
}

/* ----------------------------------------------------------------- */

