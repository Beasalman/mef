#include <Eigen/Dense>
using namespace Eigen;

#ifndef canalitica2d_h_
    #include "canalitica2d.h"
#endif

/* ----------------------------------------------------------------------- */

#ifndef canalitica02_h_
#define canalitica02_h_

class canalitica02 : public canalitica2d {

    public:

        canalitica02 ();
        double operator () (double, double, double t = 0.0);
        double derivt (double, double, double);
        Vector2d gradient (double, double, double);
        Matrix2d gradgrad (double, double, double);
};

#endif

/* ----------------------------------------------------------------------- */
