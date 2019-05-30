#include <iostream>

#include <Eigen/Dense>
using namespace Eigen;

/* ----------------------------------------------------------------------- */

#ifndef cintegra1d_h_
#define cintegra1d_h_

class cintegra1d {

    public:

        cintegra1d ();
        virtual double operator () (VectorXd, VectorXd);
};

#endif

/* ----------------------------------------------------------------------- */
