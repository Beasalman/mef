#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <Eigen/Dense>
#include <Eigen/Sparse>
using namespace Eigen;

/* --------------------------------------------------------------------------- */

#ifndef ensmat_h_
#define ensmat_h_

void ensmat (vector <int>, Matrix2d, SparseMatrix <double> &);

#endif

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

