#include <math.h>

#ifndef cvelocity1d_h_
    #include "cvelocity1d.h"
#endif

/* -------------------------------------------------------------------- */

#ifndef ccurve_h_
#define ccurve_h_

class ccurve {
    
    private:
        double deltat;
        double xini;
        double xfin;
        cvelocity1d *v;

    public:
        ccurve ();
        ccurve (cvelocity1d *, double, double, double);
        virtual double operator () (double x, double t = 0.0);
};

#endif

/* -------------------------------------------------------------------- */

