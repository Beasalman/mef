#include <cmath>
using std::abs;

#include <fstream>
#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::setprecision;
using std::setw;

#include <Eigen/Dense>
#include <Eigen/Sparse>
using namespace Eigen;

/* ------------------------------------------------------------------------------------ */

#ifndef fprint13_h_
#define fprint13_h_

void fprint13 (SparseMatrix<double> a, VectorXd b);

#endif

/* ------------------------------------------------------------------------------------ */

