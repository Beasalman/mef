#include <Eigen/Dense>
using namespace Eigen;

#ifndef cdiffusion2d_h_
    #include "cdiffusion2d.h"
#endif

/* ----------------------------------------------------------------------- */

#ifndef cdiffusion00_h_
#define cdiffusion00_h_

class cdiffusion00 : public cdiffusion2d {

    public:
        cdiffusion00 ();
        cdiffusion00 (double, double, double);
        Matrix2d operator () (double, double);
        Vector2d divergenciaT (double, double);
};

#endif

/* ----------------------------------------------------------------------- */
