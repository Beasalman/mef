#include <cmath>
using std::abs;

#include <vector>
using std::vector;

#include <Eigen/Dense>
using namespace Eigen;

#ifndef celem1d_h_
    #include "celem1d.h"
#endif
#ifndef cgauss1d_h_
    #include "cgauss1d.h"
#endif

/* -------------------------------------------------------------------------- */

#ifndef elvec1d2gdl02_h_
#define elvec1d2gdl02_h_

void elvec1d2gdl02 (celem1d *, cgauss1d *, vector <double>, vector <celem1d *>, VectorXd, Vector2d &);

#endif

/* -------------------------------------------------------------------------- */

