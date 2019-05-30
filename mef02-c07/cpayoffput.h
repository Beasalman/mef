#include <algorithm>
using std::max;

#ifndef cpayoff_h_
    #include "cpayoff.h"
#endif

/* ----------------------------------------------------------------------- */

#ifndef cpayoffput_h_
#define cpayoffput_h_

class cpayoffput : public cpayoff {

    public:

        double *strike;
        double *sinf;

        cpayoffput ();
        cpayoffput (double *, double *);
        double operator () (double);
};

#endif

/* ----------------------------------------------------------------------- */
