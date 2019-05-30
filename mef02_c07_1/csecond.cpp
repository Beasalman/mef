#include "csecond.h"

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

csecond::csecond () {}

/* ----------------------------------------------------------- */

csecond::csecond (canalitica2d *analyt, cdiffusion2d *diff, cconvection2d *velo, double) {

    this->analyt = analyt;
    this->diff = diff;
    this->velo = velo;
    this->f = f;
}

/* ----------------------------------------------------------- */

double csecond::operator () (double x, double y, double t) {}

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

