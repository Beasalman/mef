#include "canalitica00.h"

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
// Solución analítica.

canalitica00::canalitica00 () {}

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

double canalitica00::operator () (double x, double y, double t) {

    return x * (1.0 - x) * y * (1.0 - y);
}

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

double canalitica00::derivt (double x, double y, double t) {

    return 0.0;
}

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

Vector2d canalitica00::gradient (double x, double y, double t) {

    Vector2d z;
    z (0) = (1.0 - 2.0 * x) * y * (1.0 - y);
    z (1) = x * (1.0 - x) * (1.0 - 2.0 * y);

    return z;
}

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

Matrix2d canalitica00::gradgrad (double x, double y, double t) {

    Matrix2d z;
    double aux = (1.0 - 2.0 * x) * (1.0 - 2.0 * y);

    z (0,0) = -2.0 * y * (1.0 - y);
    z (0,1) = aux;
    z (1,0) = aux;
    z (1,1) = -2.0 * x * (1.0 - x);

    return z;
}

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

