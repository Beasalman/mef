#include "cfunc11.h"

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

cfunc11::cfunc11 () {

}

/* ----------------------------------------------------------- */

double cfunc11::operator () (double x, double y) {

    /*
    double z1, z2, z3, z4, u, ux, uxx, uy, uyy, uxy;

    u = x * (1.0 - x) * y * (1.0 - y);
    ux = (1.0 - 2.0 * x) * y * (1.0 - y);
    uxx = -2.0 * y * (1.0 - y);
    uy = (1.0 - 2.0 * y) * x * (1.0 - x);
    uyy = -2.0 * x * (1.0 - x);
    uxy = (1.0 - 2.0 * x) * (1.0 - 2.0 * y);

    z1 = -0.5 * this->sx * this->sx * (2.0 * ux + x * uxx) * x;
    z2 = -0.5 * this->sy * this->sy * uyy;
    z3 = -0.5 * this->rho * this->sx * this->sy * (uy + 2.0 * x * uxy);
    z4 = y * u / (1.0 - this->R);

//    return z1 + z2 + z3;                    // Sólo difusión.
    return z1 + z2 + z3 + z4;               // Difusión + reacción.
    */

    return 32.0 * (x * (1.0 - x) + y * (1.0 - y));
}

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

