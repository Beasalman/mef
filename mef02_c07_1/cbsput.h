#ifndef cbs_h_
    #include "cbs.h"
#endif
#ifndef cnormal_h_
    #include "cnormal.h"
#endif

/* ----------------------------------------------------------------------- */

#ifndef cbsput_h_
#define cbsput_h_

class cbsput : public cbs {

    public:

        double *strike;
        double *sigma;
        double *r;
        double *d0;
        double *sinf;
        double c1;
        double c2;
        cnormal *nd;

        cbsput ();
  cbsput (double *, double *, double *,  double *);
  double operator () (double, double, double);
};

#endif

/* ----------------------------------------------------------------------- */
