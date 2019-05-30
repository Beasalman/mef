#include <Eigen/Dense>
using namespace Eigen;

/* ----------------------------------------------------------------------- */

#ifndef cconvection2d_h_
    #include "cvelocity1d.h"
#endif

#ifndef cvelocity1d0_h_
#define cvelocity1d0_h_

class cvelocity1d0 : public cvelocity1d {

    public:

        double *coef;

        cvelocity1d0 ();
        cvelocity1d0 (double);
        virtual double operator () (double, double t = 0.0);
};

#endif

/* ----------------------------------------------------------------------- */
