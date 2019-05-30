#include <iostream>
using std::cout;
using std::endl;

#include <cmath>

#ifndef cintegra1d_h_
    #include "cintegra1d.h"
#endif
#ifndef csimpson1d_h_
    #include "csimpson1d.h"
#endif

/* ----------------------------------------------------------------------- */

#ifndef cnormal_h_
#define cnormal_h_

class cnormal {

    public:

        double mean;
        double std;
        cintegra1d *finteg;

        cnormal ();
        cnormal (double, double);
        double operator () (double);
};

#endif

/* ----------------------------------------------------------------------- */

