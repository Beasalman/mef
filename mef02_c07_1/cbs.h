#ifndef cnormal_h_
    #include "cnormal.h"
#endif

/* ----------------------------------------------------------------------- */

#ifndef cbs_h_
#define cbs_h_

class cbs {

    public:

        double *strike;
        double *sigma;
        double *r;
        cnormal *nd;

        cbs ();
        cbs (double *, double *, double *);
  virtual double operator () (double, double, double);
};

#endif

/* ----------------------------------------------------------------------- */
