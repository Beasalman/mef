#include <iostream>
using std::cout;
#include <vector>

#include <Eigen/Dense>
using namespace Eigen;

#ifndef celem2d_h_
    #include "celem2d.h"
#endif
// #ifndef cdiffusion00_h_
//     #include "cdiffusion00.h"
// #endif
#ifndef cgauss02_h_
    #include "cgauss02.h"
#endif

/* --------------------------------------------------------------------------- */

#ifndef mat3d12_h_
#define mat3d12_h_

void mat3d12 (celem2d *, cgauss02 *, Matrix3d &);

#endif

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

