/* ----------------------------------------------------------------------- */

#ifndef payoff_h_
#define payoff_h_

class cpayoff {

    public:

        double *strike;
        double *sinf;

        cpayoff ();
        cpayoff (double *, double *);
        virtual double operator () (double);
};

#endif

/* ----------------------------------------------------------------------- */
