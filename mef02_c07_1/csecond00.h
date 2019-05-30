#include <Eigen/Dense>
using namespace Eigen;

#ifndef csecond_h_
    #include "csecond.h"
#endif

/* ----------------------------------------------------------------------- */

#ifndef csecond00_h_
#define csecond00_h_

class csecond00 : public csecond {

    public:

        csecond00 ();
        double operator () (double, double, double t = 0.0);
};

#endif

/* ----------------------------------------------------------------------- */
