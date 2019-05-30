#include <Eigen/Dense>
using namespace Eigen;

#ifndef celem1d_h_
    #include "celem1d.h"
#endif
#ifndef cquad1d_h_
    #include "cquad1d.h"
#endif

/* ----------------------------------------------------------------- */

#ifndef elmat1d2gdl01_h_
#define elmat1d2gdl01_h_

void elmat1d2gdl01 (celem1d *, const cquad1d *, Matrix2d &);

#endif

/* ----------------------------------------------------------------- */

