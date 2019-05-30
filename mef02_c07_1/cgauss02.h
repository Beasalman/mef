#include <vector>
using std::vector;
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#ifndef cgauss02_h_
#define cgauss02_h_

/* ---------------------------------------------------------- */

class cgauss02 {

    public:
        int n;
        vector <double> x;
        vector <double> y;
        vector <double> peso;

        cgauss02 ();
        cgauss02 (int);
};

/* ---------------------------------------------------------- */

#endif
