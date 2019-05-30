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

#ifndef cdir1dcall_h_
#define cdir1dcall_h_

class cdir1dcall : public cdir1d {

    public:

        double *strike;
        double *f;
        double *sinf;
        double *d0;
        cpayoff *payoff;

        cdir1dcall ();
        cdir1dcall (double *, double *, double *, double *, cpayoff *);
        Vector2d operator () (double);
};

#endif

/* ----------------------------------------------------------------------- */
