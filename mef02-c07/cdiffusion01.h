#include <Eigen/Dense>
using namespace Eigen;

#ifndef cdiffusion2d_h_
    #include "cdiffusion2d.h"
#endif

/* ----------------------------------------------------------------------- */

#ifndef cdiffusion01_h_
#define cdiffusion01_h_

class cdiffusion01 : public cdiffusion2d {

    public:
        cdiffusion01 ();
        Matrix2d operator () (double, double);
        Vector2d divergenciaT (double, double);
};

#endif

/* ----------------------------------------------------------------------- */
