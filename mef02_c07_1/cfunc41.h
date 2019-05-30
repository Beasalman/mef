#include <Eigen/Dense>
using namespace Eigen;

/* ----------------------------------------------------------------------- */

#ifndef cfunc41_h_
#define cfunc41_h_

class cfunc41 {

    private:
        double a;

    public:
        cfunc41 (double, double, double, double, double, double, double);
        double operator () (double, double);
};

#endif

/* ----------------------------------------------------------------------- */
