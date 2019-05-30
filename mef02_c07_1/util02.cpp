#include "util02.h"

/* ------------------------------------------------------------------------------------ */

void util02 (VectorXd x, VectorXd &y) {

    /* UTIL02: Copia de un vector en otro.

    Entradas:
    - x: vector.

    Salidas:
    - y: copia de X.
    */


    int n = x.size ();

    for (int i=0; i<n; i++) {

        y (i) = x (i);
    }

}

/* ------------------------------------------------------------------------------------ */

VectorXd util02 (VectorXd x) {

    /* UTIL02: Copia de un vector en otro.

    Entradas:
    - x: vector.

    Salidas:
    - y: copia de X.
    */

    int n = x.size ();
    VectorXd y (n);
    for (int i=0; i<n; i++) {
        y (i) = x (i);
    }

    return y;
}

/* ------------------------------------------------------------------------------------ */

