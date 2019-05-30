#include "cpayoff.h"

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
// Payoff de una opción.

cpayoff::cpayoff () {}

/* ----------------------------------------------------------- */

cpayoff::cpayoff (double *strike, double *sinf) {

    this->strike = strike;
    this->sinf = sinf;
}

/* ----------------------------------------------------------- */

double cpayoff::operator () (double s) {}

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

