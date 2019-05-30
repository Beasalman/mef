#include "cdiffusion00.h"

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

cdiffusion00::cdiffusion00 (double sigma, double rho, double nuinf) {

    this->sx2 = sigma * sigma;
    this->a11 = 0.5 ;
    this->a12 = 0.5 * rho * sigma  ;
    this->a22 = 0.5 * this->sx2 /  nuinf;
}

/* ----------------------------------------------------------- */

Matrix2d cdiffusion00::operator () (double x, double y) {

    Matrix2d z;
    z (0,0) = this->a11 * x*x*y;
    z (0,1) = this->a12 * x * y;
    z (1,0) = z (0,1);
    z (1,1) = this->a22 * y;

    return z;
}

/* ----------------------------------------------------------- */

Vector2d cdiffusion00::divergenciaT (double x, double y) {

    Vector2d z;
    z (0) = this->sx2 * x;
    z (1) = this->a12;

    return z;
}

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
