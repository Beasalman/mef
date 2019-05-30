#include <vector>
using std::vector;

#include <algorithm>
using std::max;

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
#ifndef cpayoff_h_
    #include "cpayoff.h"
#endif
#ifndef positive_h_
    #include "positive.h"
#endif


/* ------------------------------------------------------------------------------- */

#ifndef dirichlet23_h_
#define dirichlet23_h_

void dirichlet23 (cmalla2d01 *, SparseMatrix <double> &);
void dirichlet23 (cmalla2d01 *, VectorXd, VectorXd, VectorXd, double, double, double, double, cpayoff *, VectorXd &);

#endif

/* ------------------------------------------------------------------------------- */
