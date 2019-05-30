#include <vector>
using std::vector;

#include <Eigen/Dense>
#include <Eigen/Sparse>
using namespace Eigen;

#ifndef cmalla2d01_h_
    #include "cmalla2d01.h"
#endif


/* ------------------------------------------------------------------------------- */

#ifndef dirichlet20_h_
#define dirichlet20_h_

void dirichlet20 (cmalla2d01 *, MatrixXd &, VectorXd &);
void dirichlet20 (cmalla2d01 *, SparseMatrix <double> &, VectorXd &);
void dirichlet20 (cmalla2d01 *, SparseMatrix <double> &);
void dirichlet20 (cmalla2d01 *, VectorXd &);

#endif

/* ------------------------------------------------------------------------------- */
