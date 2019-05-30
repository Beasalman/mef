#include <iostream>
using std::cout;
using std::endl;

#include <Eigen/Dense>
#include <Eigen/Sparse>
using namespace Eigen;

#ifndef util02_h_
    #include "util02.h"
#endif

/* ----------------------------------------------------------------------------------------------------- */

#ifndef conjgr01_h_
#define conjgr01_h_

void conjgr01 (SparseMatrix <double>, VectorXd, VectorXd &, int, double, int &, int &); 

#endif

/* ----------------------------------------------------------------------------------------------------- */

