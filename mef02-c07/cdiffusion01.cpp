#include "cdiffusion01.h"

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

cdiffusion01::cdiffusion01 () {}

/* ----------------------------------------------------------- */

Matrix2d cdiffusion01::operator () (double x, double y) {

    Matrix2d z;
    z (0,0) = 1.0;
    z (0,1) = 0.0;
    z (1,0) = 0.0;
    z (1,1) = 1.0;

    return z;
}

/* ----------------------------------------------------------- */

Vector2d cdiffusion01::divergenciaT (double x, double y) {

    Vector2d z;
    z (0) = 0.0;
    z (1) = 0.0;

    return z;
}

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

