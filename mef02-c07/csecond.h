#include <Eigen/Dense>
using namespace Eigen;

#ifndef canalitica2d_h_
    #include "canalitica2d.h"
#endif
#ifndef cconvection2d_h_
    #include "cconvection2d.h"
#endif
#ifndef cdiffusion2d_h_
    #include "cdiffusion2d.h"
#endif

/* ----------------------------------------------------------------------- */

#ifndef csecond_h_
#define csecond_h_

class csecond {

    public:
        double f;
        canalitica2d *analyt;
        cdiffusion2d *diff;
        cconvection2d *velo;

        csecond ();
        csecond (canalitica2d *, cdiffusion2d *, cconvection2d *, double);
        virtual double operator () (double, double, double t = 0.0);
};

#endif

/* ----------------------------------------------------------------------- */
