#include "canalitica02.h"

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
// Solución analítica.

canalitica02::canalitica02 () {}

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

double canalitica02::operator () (double x, double y, double t) {

    return (x - 1.0) * (2.0 - x) * (y - 1.0) * (2.0 - y);
}

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

double canalitica02::derivt (double x, double y, double t) {

    return 0.0;
}

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

Vector2d canalitica02::gradient (double x, double y, double t) {

    Vector2d z;
    z (0) = (3.0 - 2.0 * x) * (y - 1.0) * (2.0 - y);
    z (1) = (x - 1.0) * (2.0 - x) * (3.0 - 2.0 * y);

    return z;
}

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

Matrix2d canalitica02::gradgrad (double x, double y, double t) {

    double x2 = x * x;
    double y2 = y * y;

    Matrix2d z;

    z (0,0) = -2.0 * (y - 1.0) * (2.0 - y);
    z (0,1) = (3.0 - 2.0 * x) * (3.0 - 2.0 * y);
    z (1,0) = z (0,1);
    z (1,1) = -2.0 * (x - 1.0) * (2.0 - x);

    return z;
}

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

