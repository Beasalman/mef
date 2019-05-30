#include "ctrapecio1d.h"

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

ctrapecio1d::ctrapecio1d () {}

/* ----------------------------------------------------------- */
// Fórmula compuesta del trapecio.  Malla uniforme.

double ctrapecio1d::operator () (VectorXd x, VectorXd y) {

    int n = x.size ();
    double h = x (1) - x (0);
//    double z = 0.0;
//    for (int i=1; i<n-1; i++) {
//        z += y (i);
//    }
//    z = 0.5 * h * (y(0) + 2.0 * z + y(n-1));

    double z = 2.0 * y.sum () - y (0) - y(n-1);
    z = 0.5 * h * z;

    return z;
}

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

