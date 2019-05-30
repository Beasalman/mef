#include <Eigen/Dense>
using namespace Eigen;

/* ----------------------------------------------------------------------- */

#ifndef canalitica2d_h_
#define canalitica2d_h_

class canalitica2d {

    public:

        canalitica2d ();
        virtual double operator () (double, double, double t = 0.0);
        virtual double derivt (double, double, double);
        virtual Vector2d gradient (double, double, double);
        virtual Matrix2d gradgrad (double, double, double);
};

#endif

/* ----------------------------------------------------------------------- */
