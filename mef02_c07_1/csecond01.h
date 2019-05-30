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
#ifndef csecond_h_
    #include "csecond.h"
#endif

/* ----------------------------------------------------------------------- */

#ifndef csecond01_h_
#define csecond01_h_

class csecond01 : public csecond {

    public:
        csecond01 ();
        csecond01 (canalitica2d *, cdiffusion2d *, cconvection2d *, double);
        double operator () (double, double, double t = 0.0);
};

#endif

/* ----------------------------------------------------------------------- */
