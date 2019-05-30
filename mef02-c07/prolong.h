#include <iostream>
using std::cout;
using std::endl;

#include <map>
using std::map;

#include <Eigen/Dense>
using namespace Eigen;

#ifndef cnodo2d_h_
    #include "cnodo2d.h"
#endif
#ifndef cmalla2d01_h_
    #include "cmalla2d01.h"
#endif

#ifndef prolong_h_
#define prolong_h_

/* --------------------------------------------------------------------------- */

void prolong (cmalla2d01 *, VectorXd, cmalla2d01 *, VectorXd &);

/* --------------------------------------------------------------------------- */

#endif
