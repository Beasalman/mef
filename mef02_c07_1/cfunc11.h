#include <Eigen/Dense>
using namespace Eigen;

/* ----------------------------------------------------------------------- */

#ifndef cfunc11_h_
#define cfunc11_h_

class cfunc11 {

    private:
        double sx;
        double sy;
        double rho;
        double R;

    public:
        cfunc11 ();
        double operator () (double, double);
};

#endif

/* ----------------------------------------------------------------------- */
