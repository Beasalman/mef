#include "cvelocity1d0.h"

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
// Campo de velocidades del problema 1D.

cvelocity1d0::cvelocity1d0 () {}

/* ----------------------------------------------------------- */

cvelocity1d0::cvelocity1d0 (double rr) {

    double c = - rr;
    this->coef = &c;
}

/* ----------------------------------------------------------- */

double cvelocity1d0::operator () (double x, double tau) {

    return (*this->coef) * x;
}

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

