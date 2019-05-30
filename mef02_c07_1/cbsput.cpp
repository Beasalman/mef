#include "cbsput.h"

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
// Valor de una opción Put.
// Fórmula analítica de Black-Scholes.
// Incluye dividendos.

cbsput::cbsput () {}

/* ----------------------------------------------------------- */

cbsput::cbsput (double *strike, double *r, double *d0, double *sinf) {

    this->strike = strike;
    this->r = r;
    this->d0 = d0;
    this->sinf = sinf;
    this->nd = new cnormal ();
}

/* ----------------------------------------------------------- */

double cbsput::operator () (double s, double nu, double tau) {

    // ******************************************************************************************************************
    //cout << " [CBSPUT]        s: " << s << endl;
    // ******************************************************************************************************************

    double z = 0.0;
    if (s > 0.0) {
        double ssinf = s * (*this->sinf);
        double sigma1d = nu;
        double c1 =  *this->r - *this->d0 + 0.5 * sigma1d *sigma1d;
        double c2 =  *this->r - *this->d0 - 0.5 * sigma1d *sigma1d;
        double d1 = (log (ssinf/(*this->strike)) + c1 * tau) / (sigma1d * sqrt (tau));
        double d2 = (log (ssinf/(*this->strike)) + c2 * tau) / (sigma1d * sqrt (tau));
        z = (*this->strike) * exp (-(*this->r) * tau) * (*this->nd) (-d2) 
          - ssinf * exp (-(*this->d0) * tau) * (*this->nd) (-d1);

    } else {
        z = (*this->strike) * exp (-(*this->r) * tau) - s * (*this->sinf) * exp (-(*this->d0) * tau);
    }
    return z;
}

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

