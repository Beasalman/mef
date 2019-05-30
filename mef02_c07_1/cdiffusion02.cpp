#include "cdiffusion02.h"

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

cdiffusion02::cdiffusion02 () {}

/* ----------------------------------------------------------- */

Matrix2d cdiffusion02::operator () (double x, double y) {

    Matrix2d z;
    z (0,0) = x;
    z (0,1) = x;
    z (1,0) = x;
    z (1,1) = y;

    return z;
}

/* ----------------------------------------------------------- */

Vector2d cdiffusion02::divergenciaT (double x, double y) {

    Vector2d z;
    z (0) = 1.0;
    z (1) = 2.0;

    return z;
}

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

