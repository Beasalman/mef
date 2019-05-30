#include <iostream>
using std::cout;
using std::endl;

#include <math.h>

#ifndef ccurve_h_
    #include "ccurve.h"
#endif
#ifndef cvelocity1d_h_
    #include "cvelocity1d.h"
#endif

/* -------------------------------------------------------------------- */

#ifndef ccurve01_h_
#define ccurve01_h_

class ccurve01 : public ccurve {
    
    private:
        double coef;
        double deltat;
        double xini;
        double xfin;
        cvelocity1d *v;

    public:
        ccurve01 (cvelocity1d *, double, double, double);
        double operator () (double x, double t = 0.0);
};

#endif

/* -------------------------------------------------------------------- */

