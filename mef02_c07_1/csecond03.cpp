#include "csecond03.h"

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

csecond03::csecond03 () {}

/* ------------------------------------------------------------------------- */

csecond03::csecond03 (canalitica2d *analyt, cdiffusion2d *diff, cconvection2d *velo, double) {

    this->analyt = analyt;
    this->diff = diff;
    this->velo = velo;
    this->f = f;
}

/* ------------------------------------------------------------------------- */

double csecond03::operator () (double x, double y, double t) {

    /* CSECOND03: Segundo miembro.

    Entradas:
    - x,y: 
    - t:   tiempo real.
    */

    double u = (*this->analyt) (x,y,t);
    double ut = this->analyt->derivt (x,y,t);
    Vector2d gradu = this->analyt->gradient (x,y,t);
    Matrix2d ggradu = this->analyt->gradgrad (x,y,t);

    Matrix2d a = (*this->diff) (x,y);
    Vector2d divaT = this->diff->divergenciaT (x,y);
    Vector2d b = (*this->velo) (x,y);

    double aux = a (0,0) * ggradu (0,0) + a (1,0) * ggradu (0,1) + a (0,1) * ggradu (1,0) + a (1,1) * ggradu (1,1);         // dot (a.T, ggradu), producto interior.

    return -(ut + (divaT.dot (gradu) + aux) - b.dot (gradu) - this->f * u);
}

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

