#include <Eigen/Sparse>
using namespace Eigen;

#ifndef cfrontera1d_h_
    #include "cfrontera1d.h"
#endif
#ifndef cmalla1d_h_
    #include "cmalla1d.h"
#endif
#ifndef cnodo1d_h_
    #include "cnodo1d.h"
#endif

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

#ifndef dirichlet00_h_
#define dirichlet00_h_

void dirichlet00 (cmalla1d *, SparseMatrix <double> &);
void dirichlet00 (cmalla1d *, VectorXd &);
void dirichlet00 (cmalla1d *, VectorXd &, Vector2d);

#endif


/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

