#include <iostream>
using std::cout;
#include <vector>

#include <Eigen/Dense>
using namespace Eigen;

#ifndef celem2d_h_
    #include "celem2d.h"
#endif
#ifndef cgauss02_h_
    #include "cgauss02.h"
#endif

/* --------------------------------------------------------------------------- */

#ifndef vec3d12_h_
#define vec3d12_h_

void vec3d12 (celem2d *, cgauss02 *, Vector3d, Vector3d &);

#endif

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

