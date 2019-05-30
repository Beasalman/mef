#include <iostream>

#include <Eigen/Dense>
using namespace Eigen;

#ifndef cintegra1d_h_
    #include "cintegra1d.h"
#endif

/* ----------------------------------------------------------------------- */

#ifndef ctrapecio1d_h_
#define ctrapecio1d_h_

class ctrapecio1d : public cintegra1d {

    public:

        ctrapecio1d ();
        double operator () (VectorXd, VectorXd);
};

#endif

/* ----------------------------------------------------------------------- */
