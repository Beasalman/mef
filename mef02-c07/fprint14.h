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

#ifndef fprint14_h_
#define fprint14_h_

void fprint14 (SparseMatrix<double> a, VectorXd b);

#endif

/* ------------------------------------------------------------------------------------ */

