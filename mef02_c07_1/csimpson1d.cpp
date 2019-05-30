#include "csimpson1d.h"

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

csimpson1d::csimpson1d () {}

/* ----------------------------------------------------------- */
// Fórmula compuesta de Simpson.  Malla uniforme.

double csimpson1d::operator () (VectorXd x, VectorXd y) {

    int n = (x.size () - 1) / 2;
    double h = x (1) - x (0);
    double z = 0.0;

    for (int i=1; i<=n; i++) {
        z += y (2*i-2) + 4.0 * y (2*i-1) + y (2*i);
    }
    z = (h / 3.0) * z;

    return z;
}

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

