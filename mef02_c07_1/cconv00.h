#include <Eigen/Dense>
using namespace Eigen;

#ifndef cconvection2d_h_
    #include "cconvection2d.h"
#endif

/* ----------------------------------------------------------------------- */

#ifndef cconv00_h_
#define cconv00_h_

class cconv00 : public cconvection2d {

    public:
        cconv00 (double, double, double, double, double, double);
        Vector2d operator () (double, double);
};

#endif

/* ----------------------------------------------------------------------- */

