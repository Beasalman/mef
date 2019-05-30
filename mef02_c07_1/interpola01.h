#include <iostream>
using std::cout;
using std::endl;

#include <map>
using std::map;

#include <set>
using std::set;

#include <Eigen/Dense>
using namespace Eigen;

#ifndef cnodo2d_h_
    #include "cnodo2d.h"
#endif
#ifndef cmalla2d01_h_
    #include "cmalla2d01.h"
#endif

#ifndef interpola01_h_
#define interpola01_h_

/* --------------------------------------------------------------------------- */

void interpola01 (cmalla2d01 *, VectorXd, cmalla1d *, VectorXd &);

/* --------------------------------------------------------------------------- */

#endif
