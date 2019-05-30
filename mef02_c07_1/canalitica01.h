#include <Eigen/Dense>
using namespace Eigen;

#ifndef canalitica2d_h_
    #include "canalitica2d.h"
#endif

/* ----------------------------------------------------------------------- */

#ifndef canalitica01_h_
#define canalitica01_h_

class canalitica01 : public canalitica2d {

    public:

        canalitica01 ();
        double operator () (double, double, double t = 0.0);
        double derivt (double, double, double);
        Vector2d gradient (double, double, double);
        Matrix2d gradgrad (double, double, double);
};

#endif

/* ----------------------------------------------------------------------- */
