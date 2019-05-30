#include "cdir1dcall.h"

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
// Condiciones de contorno del problema 1D.
// Caso de una opción Call.

cdir1dcall::cdir1dcall () {}

/* ----------------------------------------------------------- */

cdir1dcall::cdir1dcall (double *strike, double *f, double *sinf, double *d0, cpayoff *payoff) {

    this->strike = strike;
    this->f = f;
    this->sinf = sinf;
    this->d0 = d0;
    this->payoff = payoff;
}

/* ----------------------------------------------------------- */

Vector2d cdir1dcall::operator () (double tau) {

    double z1 = (*this->sinf) * exp (-(*this->d0) * tau) - (*this->strike) * exp (-(*this->f) * tau);
    double g0 = (*this->payoff) (0.0);
    double g1 = (*this->payoff) (1.0);           // Extremo superior (en S) del dominio.

    Vector2d z;
    z << max (0.0, g0), max (z1, g1);

    return z;
}

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

