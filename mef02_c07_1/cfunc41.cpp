#include "cfunc41.h"

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

cfunc41::cfunc41 (double sx, double sy, double rho, double r, double q, double k, double R) {

    this->a = 1.0 / (1.0 - R);
}

/* ----------------------------------------------------------- */

double cfunc41::operator () (double x, double y) {

    double z, f;
    z = this->a * y;
    f = 0.0;

    return 0.0;
//    return z + f;
}

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
