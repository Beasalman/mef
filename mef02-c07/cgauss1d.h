#include <vector>
using std::vector;
#include <math.h>

#ifndef cgauss1d_h_
#define cgauss1d_h_

/* ---------------------------------------------------------- */

class cgauss1d {

    public:
        int n;
        vector <double> x;
        vector <double> peso;

        cgauss1d (int);
};

/* ---------------------------------------------------------- */

#endif 
