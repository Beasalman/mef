#include "elmat1d2gdl01.h"

/* ----------------------------------------------------------------- */

void elmat1d2gdl01 (celem1d *ef, const cquad1d *g, Matrix2d &a) {

    /* ELMAT1D2GDL01: Matriz elemental
                      Problema 1-D, un grado de libertad por nodo.
                      Término de difusión: Int [u' v' dx]
      
    Entradas:
    - ef: elemento actual.
    - g: nodos y pesos de integracion.
     
    Entrada/salida:
    - a: matriz elemental.
    */

    MatrixXd dp (1,2);
    Matrix2d dptdp;

    dp (0) = -0.5;
    dp (1) =  0.5;
    dptdp = dp.transpose () * dp;

    for (int i=0; i<g->n; i++) {
        a += g->peso[i] * dptdp;
    }
    a = a * (1.0 / ef->jac);
}

/* ----------------------------------------------------------------- */

