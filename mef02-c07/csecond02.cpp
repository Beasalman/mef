#include "csecond02.h"

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

csecond02::csecond02 () {}

/* ----------------------------------------------------------- */


csecond02::csecond02 (sx, sy, rho, hinf, r, rsmall, q, k, f) {

    this->sx = sx;
    this->sy = sy;
    this->rho = r;
    this->r = r;
    this->rsmall = rsmall;
    this->q = q;
    this->kappa = k;
    this->hinf = hinf;
    this->f = f;

    this->sx2 = sx * sx;
    this->c2sx2 = 0.5 * this->sx2;
    this->c2sy2h2 = 0.5 * sy * sy / (hinf * hinf);
    this->c2rsxsyh = 0.4 * rho * sx * sy / hinf;
    this->csx2rq = this->sx2 - (rsmall - q);
    this->k1r = k / (1.0 - r);
}

/* ----------------------------------------------------------- */

double csecond02::operator () (double x, double y, double t) {

    // Solución analítica.

    double x2 = x * x;
    double y2 = y * y;
    double umx = 1.0 - x;
    double umy = 1.0 - y;
    double u = x2 * umx * y2 * umy * (t + 1.0);

    // Derivada temporal, gradiente y gradiente del gradiente.

    double ut = x2 * umx * y2 * umy;

    Vector2d gradu;
    gradu (0) = (2.0 - 3.0 * x) * x * y2 * umy;
    gradu (1) = x2 * umx * (2.0 - 3.0 * y) * y;

//    ggradu (0,0) = (2.0 - 6.0 * x) * y2 * umy;
//    ggradu (0,1) = (2.0 - 3.0 * x) * x * (2.0 - 3.0 * y) * y;
//    ggradu (1,0) = (2.0 - 3.0 * x) * x * (2.0 - 3.0 * y) * y;
//    ggradu (1,1) = x2 * umx * (2.0 - 6.0 * y);

    Matrix2d ggradu = this->gradgradu (x,y);

    // Matriz de difusión y divergencia de su traspuesta.

//    Matrix2d a;
//    a (0,0) = this->c2sx2 * x2;
//    a (0,1) = this->c2rsxsyh * x;
//    a (1,0) = this->c2rsxsyh * x;
//    a (1,1) = this->c2rsxsyh;
//    Vector2d divaT;
//    divaT (0) = this->sx2 * x;
//    divaT (1) = this->c2rsxsyh;

    Matrix2d a = this->diff (x,y);
    Vector2d divaT = this->diver (x,y);

    // Vector velocidad.

//    b (0) = this->csx2rq * x;
//    b (1) = this->c2rsxsyh + this->k1r * y;

    Vector2d b = this->velocity (x,y);

    // Segundo miembro.

    return ut + divaT.dot (gradu) + (a.transpose()).dot (ggradu) + b.dot (gradu) + this->f * u;
}

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

