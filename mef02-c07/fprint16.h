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

#ifndef fprint16_h_
#define fprint16_h_

void fprint16 (SparseMatrix<double> a, VectorXd b);

#endif

/* ------------------------------------------------------------------------------------ */

