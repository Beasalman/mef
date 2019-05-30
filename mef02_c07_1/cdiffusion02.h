#include <Eigen/Dense>
using namespace Eigen;

#ifndef cdiffusion2d_h_
    #include "cdiffusion2d.h"
#endif

/* ----------------------------------------------------------------------- */

#ifndef cdiffusion02_h_
#define cdiffusion02_h_

class cdiffusion02 : public cdiffusion2d {

    public:
        cdiffusion02 ();
        Matrix2d operator () (double, double);
        Vector2d divergenciaT (double, double);
};

#endif

/* ----------------------------------------------------------------------- */
