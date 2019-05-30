#include <iostream>
using std::cout;
#include <vector>

#include <Eigen/Dense>
using namespace Eigen;

#ifndef celem2d_h_
    #include "celem2d.h"
#endif
#ifndef csecond_h_
    #include "csecond.h"
#endif
#ifndef cgauss02_h_
    #include "cgauss02.h"
#endif

/* --------------------------------------------------------------------------- */

#ifndef vec3d11_h_
#define vec3d11_h_

void vec3d11 (celem2d *, cgauss02 *, csecond *, Vector3d &, double);
void vec3d11 (celem2d *, cgauss02 *, csecond *, Vector3d &);

#endif

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

