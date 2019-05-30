#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <algorithm>
using std::min;

#include <Eigen/Dense>
#include <Eigen/Sparse>
using namespace Eigen;

//#ifndef ctriplet_h_
//    #include "ctriplet.h"
//#endif
#ifndef matvecreduce_h_
    #include "matvecreduce.h"
#endif
#ifndef util02_h_
    #include "util02.h"
#endif

/* --------------------------------------------------------------------------- */

#ifndef alas_h_
#define alas_h_

void alas (SparseMatrix <double>, VectorXd, VectorXd, VectorXd &, double, double, 
           int, int &);

#endif

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

