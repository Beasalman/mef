#include "cconv00.h"

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

cconv00::cconv00 (double sigma, double rho, double rr, double theta, double kappa, double nuinf) {

    this->a01 = nuinf;
    this->a02 = 0.5 * rho * sigma  - rr;
    this->a20 = 0.5 * sigma * sigma  / nuinf - kappa * theta / nuinf;
    this->a21 = 0.5 * rho * sigma - kappa;
}

/* ----------------------------------------------------------- */

Vector2d cconv00::operator () (double x, double y) {

    Vector2d z;

    z (0) = this->a01 * y * x + this->a02 *x ;
    z (1) = this->a20 + this->a21 * y;

    return z;
}

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

