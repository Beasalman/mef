#include "ccurve01.h"

/* ------------------------------------------------------------------- */

ccurve01::ccurve01 (cvelocity1d *v, double deltat, double xini, double xfin) {

    this->coef = 0.0;
    this->deltat = deltat;
    this->xini = xini;
    this->xfin = xfin;
    this->v = v;
}

/* ------------------------------------------------------------------- */

double ccurve01::operator () (double x, double t) {

    // El segundo argumento (t) está definido por defecto y es opcional.

    double z = x - (*this->v)(x) * this->deltat;
    if (z < this->xini) z = this->xini;
    if (z > this->xfin) z = this->xfin;
    return z;
}

/* ------------------------------------------------------------------- */
