#include <algorithm>
using std::max;

#ifndef cpayoff_h_
    #include "cpayoff.h"
#endif

/* ----------------------------------------------------------------------- */

#ifndef cpayoffcall_h_
#define cpayoffcall_h_

class cpayoffcall : public cpayoff {

    public:

        double *strike;
        double *sinf;

        cpayoffcall ();
        cpayoffcall (double *, double *);
        double operator () (double);
};

#endif


/* ----------------------------------------------------------------------- */
