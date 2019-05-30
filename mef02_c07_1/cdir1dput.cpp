#include "cdir1dput.h"

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
// Condiciones de contorno del problema 1D.
// Caso de una opción Put.

cdir1dput::cdir1dput () {}

/* ----------------------------------------------------------- */

cdir1dput::cdir1dput (double *strike, double *f, double *sinf, double *d0, cpayoff *payoff) {

    this->strike = strike;
    this->f = f;
    this->sinf = sinf;
    this->d0 = d0;
    this->payoff = payoff;
}

/* ----------------------------------------------------------- */

Vector2d cdir1dput::operator () (double tau) {

    double z1 = (*this->strike) * exp (-(*this->f) * tau);
    double g0 = (*this->payoff) (0.0);
    double g1 = (*this->payoff) (1.0);           // Extremo superior (en S) del dominio.

    Vector2d z;
    z << max (z1, g0), max (0.0, g1);

    return z;
}

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

