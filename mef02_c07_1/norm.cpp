#include "norm.h"

/* ------------------------------------------------------------------------------------ */

double norm (VectorXd x) {

    /* NORM: Norma de un vector.

    Entradas:
    - x: vector.

    Salidas:
    - z: norma de X.
    */

    double z = 0.0;
    for (int i=0; i<x.size(); i++) {
        z += x (i) * x (i);
    }
    return sqrt (z);
}

/* ------------------------------------------------------------------------------------ */

