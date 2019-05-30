#include <cmath>
using std::abs;

#include <vector>
using std::vector;

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

#ifndef fprint15_h_
#define fprint15_h_

void fprint15 (SparseMatrix<double> a, VectorXd b);

#endif

/* ------------------------------------------------------------------------------------ */

