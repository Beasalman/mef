#include "cpayoffput.h"

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
// Payoff de una opción PUT.

cpayoffput::cpayoffput () {}

/* ----------------------------------------------------------- */

cpayoffput::cpayoffput (double *strike, double *sinf) {

    this->strike = strike;
    this->sinf = sinf;
}

/* ----------------------------------------------------------- */

double cpayoffput::operator () (double s) {

    return max (0.0, *this->strike - (*this->sinf) * s);
}

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

