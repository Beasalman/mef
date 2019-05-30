#include <Eigen/Dense>
using namespace Eigen;

/* ----------------------------------------------------------------------- */

#ifndef cconvection2d_h_
#define cconvection2d_h_

class cconvection2d {

    public:
        double a01;
        double a02;
        double a20;
        double a21;

        cconvection2d ();
        cconvection2d (double, double, double, double, double, double);
        virtual Vector2d operator () (double, double);
};

#endif

/* ----------------------------------------------------------------------- */
