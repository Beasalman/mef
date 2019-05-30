#include <iostream>

#include <Eigen/Dense>
using namespace Eigen;

#ifndef cintegra1d_h_
    #include "cintegra1d.h"
#endif

/* ----------------------------------------------------------------------- */

#ifndef csimpson1d_h_
#define csimpson1d_h_

class csimpson1d : public cintegra1d {

    public:

        csimpson1d ();
        double operator () (VectorXd, VectorXd);
};

#endif

/* ----------------------------------------------------------------------- */
