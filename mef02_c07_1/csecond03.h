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

#ifndef csecond03_h_
#define csecond03_h_

class csecond03 : public csecond {

    public:
        csecond03 ();
        csecond03 (canalitica2d *, cdiffusion2d *, cconvection2d *, double);
        double operator () (double, double, double t = 0.0);
};

#endif

/* ----------------------------------------------------------------------- */
