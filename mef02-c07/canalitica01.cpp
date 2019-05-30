#include "canalitica01.h"

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
// Solución analítica.

canalitica01::canalitica01 () {}

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
// El tercer argumento (t) es el tiempo real.

double canalitica01::operator () (double x, double y, double t) {

    return x*x * (1.0 - x) * y*y * (1.0 - y) * (t + 1.0);
}

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

double canalitica01::derivt (double x, double y, double t) {

    return x*x * (1.0 - x) * y*y * (1.0 - y);
}

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

Vector2d canalitica01::gradient (double x, double y, double t) {

    double x2 = x * x;
    double y2 = y * y;

    Vector2d z;
    z (0) = (2.0 - 3.0 * x) * x * y2 * (1.0 - y);
    z (1) = x2 * (1.0 - x) * (2.0 - 3.0 * y) * y;

    return z * (t + 1.0);
}

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

Matrix2d canalitica01::gradgrad (double x, double y, double t) {

    double x2 = x * x;
    double y2 = y * y;

    Matrix2d z;

    z (0,0) = (2.0 - 6.0 * x) * y2 * (1.0 - y);
    z (0,1) = (2.0 - 3.0 * x) * x * (2.0 - 3.0 * y) * y;
    z (1,0) = z (0,1);
    z (1,1) = x2 * (1.0 - x) * (2.0 - 6.0 * y);

    return z * (t + 1.0);
}

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

