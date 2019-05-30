#include <math.h>
#include <cmath>
using std::abs;

#include <Eigen/Dense>
using namespace Eigen;

/* ----------------------------------------------------------------------- */

#ifndef cdiffusion2d_h_
#define cdiffusion2d_h_

class cdiffusion2d {

    public:
        double sx2;
        double a11;
        double a12;
        double a22;

        cdiffusion2d ();
        cdiffusion2d (double, double, double);
        virtual Matrix2d operator () (double, double);
        virtual Vector2d divergenciaT (double, double);
};

#endif

/* ----------------------------------------------------------------------- */
