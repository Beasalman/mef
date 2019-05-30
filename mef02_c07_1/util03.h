#include <iostream>
using std::cout;
using std::endl;

#include <Eigen/Dense>
using namespace Eigen;

#ifndef canalitica2d_h_
    #include "canalitica2d.h"
#endif
#ifndef cmalla2d01_h_
    #include "cmalla2d01.h"
#endif
#ifndef cnodo2d_h_
    #include "cnodo2d.h"
#endif

/* ------------------------------------------------------------------------------------ */

#ifndef util03_h_
#define util03_h_

VectorXd util03 (cmalla2d01 *, canalitica2d *, double);

#endif

/* ------------------------------------------------------------------------------------ */

