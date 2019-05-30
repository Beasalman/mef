#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <Eigen/Dense>
#include <Eigen/Sparse>
using namespace Eigen;

//#ifndef ctriplet_h_
//    #include "ctriplet.h"
//#endif

/* --------------------------------------------------------------------------- */

#ifndef matvecreduce_h_
#define matvecreduce_h_

void matvecreduce (SparseMatrix <double>, vector <int>, SparseMatrix <double> &);
void matvecreduce (SparseMatrix <double>, vector <int>, vector <int>, SparseMatrix <double> &);
void matvecreduce (VectorXd, vector <int>, VectorXd &);

#endif

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

