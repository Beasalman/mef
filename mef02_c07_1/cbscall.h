#ifndef cbs_h_
    #include "cbs.h"
#endif
#ifndef cnormal_h_
    #include "cnormal.h"
#endif

/* ----------------------------------------------------------------------- */

#ifndef cbscall_h_
#define cbscall_h_

class cbscall : public cbs {

    public:

        double *strike;
        double *sigma;
        double *r;
        double *d0;
        double *sinf;
        double c1;
        double c2;
        cnormal *nd;

        cbscall ();
  cbscall (double *, double *, double *, double *);
        double operator () (double, double, double);
};

#endif

/* ----------------------------------------------------------------------- */
