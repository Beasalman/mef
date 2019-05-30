#include <iostream>
using std::cout;
using std::endl;

#include <algorithm>
using std::max;

#include <Eigen/Dense>
using namespace Eigen;

#ifndef cdir1d_h_
    #include "cdir1d.h"
#endif
#ifndef cpayoff_h_
    #include "cpayoff.h"
#endif

/* ----------------------------------------------------------------------- */

#ifndef cdir1dput_h_
#define cdir1dput_h_

class cdir1dput : public cdir1d {

    public:

        double *strike;
        double *f;
        double *sinf;
        double *d0;
        cpayoff *payoff;

        cdir1dput ();
        cdir1dput (double *, double *, double *, double *, cpayoff *);
        Vector2d operator () (double);
};

#endif

/* ----------------------------------------------------------------------- */
