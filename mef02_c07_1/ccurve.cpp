#include "ccurve.h"

/* ------------------------------------------------------------------- */

ccurve::ccurve () {}

/* ------------------------------------------------------------------- */

ccurve::ccurve (cvelocity1d *v, double deltat, double xini, double xfin) {

    this->deltat = deltat;
    this->xini = xini;
    this->xfin = xfin;
    this->v = v;
}

/* ------------------------------------------------------------------- */

double ccurve::operator () (double x, double t) {} 

/* ------------------------------------------------------------------- */
