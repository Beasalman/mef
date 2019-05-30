#include <Eigen/Dense>
using namespace Eigen;

/* ----------------------------------------------------------------------- */

#ifndef cvelocity1d_h_
#define cvelocity1d_h_

class cvelocity1d {

    public:

        double *coef;

        cvelocity1d ();
        cvelocity1d (double, double);
        virtual double operator () (double, double t = 0.0);
};

#endif

/* ----------------------------------------------------------------------- */
