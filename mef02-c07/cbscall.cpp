#include "cbscall.h"

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
// Valor de una opción CALL.
// Fórmula analítica de Black-Scholes.

cbscall::cbscall () {}

/* ----------------------------------------------------------- */

cbscall::cbscall (double *strike, double *r, double *d0, double *sinf) {

    this->strike = strike;
    this->r = r;
    this->d0 = d0;
    this->sinf = sinf;
    this->nd = new cnormal ();
}

/* ----------------------------------------------------------- */

double cbscall::operator () (double s, double nu, double tau) {

    double z = 0.0;
    if (s > 0.0) {
        double ssinf = s * (*this->sinf);
        double sigma1d = nu;
        double c1 =  *this->r - *this->d0 + 0.5 * sigma1d *sigma1d;
        double c2 =  *this->r - *this->d0 - 0.5 * sigma1d *sigma1d;
        double d1 = (log (ssinf/(*this->strike)) + c1 * tau) / (sigma1d * sqrt (tau));
        double d2 = (log (ssinf/(*this->strike)) + c2 * tau) / (sigma1d * sqrt (tau));
        z = ssinf * exp (-(*this->d0) * tau) * (*this->nd) (d1) 
          - (*this->strike) * exp (-(*this->r) * tau) * (*this->nd) (d2);
    }
    return z;
}

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

