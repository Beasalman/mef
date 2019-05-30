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
#ifndef cnodo2d_h_
    #include "cnodo2d.h"
#endif


/* ------------------------------------------------------------------------------- */

#ifndef dirichlet22z_h_
#define dirichlet22z_h_

void dirichlet22z (cmalla2d01 *, SparseMatrix <double> &);
void dirichlet22z (cmalla2d01 *, VectorXd, VectorXd, double, double, VectorXd &);

#endif

/* ------------------------------------------------------------------------------- */
