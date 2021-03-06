#include "cconvection2d.h"

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
// Vector de convección.

cconvection2d::cconvection2d () {}

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

cconvection2d::cconvection2d (double sigma, double rho, double rr, double theta, double kappa, double nuinf) {

    this->a01 = nuinf;
    this->a02 = 0.5 * rho * sigma  - rr;
    this->a20 = 0.5 * sigma * sigma  / nuinf - kappa * theta / nuinf;
    this->a21 = 0.5 * rho * sigma - kappa;
}

/* ----------------------------------------------------------- */

Vector2d cconvection2d::operator () (double x, double y) {}

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
