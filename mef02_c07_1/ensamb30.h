#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <Eigen/Dense>
#include <Eigen/Sparse>
using namespace Eigen;

/* --------------------------------------------------------------------------- */

#ifndef ensamb30_h_
#define ensamb30_h_

void ensamb30 (vector<int>, Matrix3d, Vector3d, MatrixXd &, VectorXd &);
void ensamb30 (vector<int>, Matrix3d, Vector3d, SparseMatrix <double> &, VectorXd &);
void ensamb30 (vector<int>, Matrix3d, SparseMatrix <double> &);
void ensamb30 (vector<int>, Vector3d, VectorXd &);

#endif

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

