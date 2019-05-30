#include <iostream>
using std::cout;
using std::endl;

#include <Eigen/Dense>
using namespace Eigen;

#ifndef cpayoff_h_
    #include "cpayoff.h"
#endif

/* ----------------------------------------------------------------------- */

#ifndef cdir1d_h_
#define cdir1d_h_

class cdir1d {

    public:

        double *strike;
        double *f;
        double *sinf;
        double *d0;
        cpayoff *payoff;

        cdir1d ();
        cdir1d (double *, double *, double *, double *, cpayoff *);
        virtual Vector2d operator () (double);
};

#endif

/* ----------------------------------------------------------------------- */
