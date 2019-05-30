#include "cdir1d.h"

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
// Condiciones de contorno del problema 1D.

cdir1d::cdir1d () {}

/* ----------------------------------------------------------- */

cdir1d::cdir1d (double *strike, double *f, double *sinf, double *d0, cpayoff *payoff) {

    this->strike = strike;
    this->f = f;
    this->sinf = sinf;
    this->d0 = d0;
    this->payoff = payoff;
}

/* ----------------------------------------------------------- */

Vector2d cdir1d::operator () (double tau) {}

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

