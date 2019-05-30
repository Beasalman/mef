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

#ifndef bicgstab01_h_
#define bicgstab01_h_

void bicgstab01 (SparseMatrix <double>, VectorXd, VectorXd &, int, double, int &, int &);

#endif

/* ----------------------------------------------------------------------------------------------------- */

