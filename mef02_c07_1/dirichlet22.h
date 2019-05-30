#include <vector>
using std::vector;

#include <Eigen/Dense>
#include <Eigen/Sparse>
using namespace Eigen;

#ifndef celem2d_h_
    #include "celem2d.h"
#endif
#ifndef cfrontera2d_h_
    #include "cfrontera2d.h"
#endif
#ifndef cmalla2d01_h_
    #include "cmalla2d01.h"
#endif
#ifndef cmalla1d_h_
    #include "cmalla1d.h"
#endif
#ifndef cnodo2d_h_
    #include "cnodo2d.h"
#endif


/* ------------------------------------------------------------------------------- */

#ifndef dirichlet22_h_
#define dirichlet22_h_

void dirichlet22 (cmalla2d01 *, SparseMatrix <double> &);
void dirichlet22 (cmalla2d01 *, VectorXd, VectorXd, double, double, VectorXd &);
void dirichlet22 (cmalla2d01 *, VectorXd, VectorXd &);
//void dirichlet22 (cmalla2d01 *, float*, VectorXd &);
void dirichlet22 (cmalla2d01 *, cmalla1d *, VectorXd, VectorXd, VectorXd &);

#endif

/* ------------------------------------------------------------------------------- */
