#include "cpayoffcall.h"

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
// Payoff de una opción CALL.

cpayoffcall::cpayoffcall () {}

/* ----------------------------------------------------------- */

cpayoffcall::cpayoffcall (double *strike, double *sinf) {

    this->strike = strike;
    this->sinf = sinf;
}

/* ----------------------------------------------------------- */

double cpayoffcall::operator () (double s) {

    return max (0.0, (*this->sinf) * s - *this->strike); 
}

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

