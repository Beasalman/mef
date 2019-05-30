#include <vector>
using std::vector;

#include <Eigen/Dense>
#include <Eigen/Sparse>
using namespace Eigen;

#ifndef cfrontera2d_h_
    #include "cfrontera2d.h"
#endif
#ifndef cmalla2d01_h_
    #include "cmalla2d01.h"
#endif
#ifndef cnodo2d_h_
    #include "cnodo2d.h"
#endif


/* ------------------------------------------------------------------------------- */

#ifndef dirichlet21_h_
#define dirichlet21_h_

void dirichlet21 (cmalla2d01 *, double (*)(double,double), SparseMatrix <double> &, VectorXd &);
void dirichlet21 (cfrontera2d *, double (*)(double,double), SparseMatrix <double> &, VectorXd &);

#endif

/* ------------------------------------------------------------------------------- */
