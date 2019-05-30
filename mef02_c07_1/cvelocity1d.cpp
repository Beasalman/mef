#include "cvelocity1d.h"

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
// Campo de velocidades del problema 1D.

cvelocity1d::cvelocity1d () {}

/* ----------------------------------------------------------- */

cvelocity1d::cvelocity1d (double sigma, double rr) {

    double c = sigma - rr;
    this->coef = &c;
}

/* ----------------------------------------------------------- */

double cvelocity1d::operator () (double x, double tau) {

    return (*this->coef) * x;
}

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

