#include <Eigen/Dense>
using namespace Eigen;

#ifndef celem1d_h_
    #include "celem1d.h"
#endif
#ifndef cgauss1d_h_
    #include "cgauss1d.h"
#endif

/* ----------------------------------------------------------------- */

#ifndef elmat1d2gdl03_h_
#define elmat1d2gdl03_h_

void elmat1d2gdl03 (celem1d *, const cgauss1d *, Matrix2d &);

#endif

/* ----------------------------------------------------------------- */

