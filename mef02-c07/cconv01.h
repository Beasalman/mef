#include <Eigen/Dense>
using namespace Eigen;

#ifndef cconvection2d_h_
    #include "cconvection2d.h"
#endif

/* ----------------------------------------------------------------------- */

#ifndef cconv01_h_
#define cconv01_h_

class cconv01 : public cconvection2d {

    public:
        cconv01 (double, double, double, double, double, double);
        Vector2d operator () (double, double);
};

#endif

/* ----------------------------------------------------------------------- */

