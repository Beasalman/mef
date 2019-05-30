#include <iostream>
using std::cout;
#include <vector>

#include <Eigen/Dense>
using namespace Eigen;

#ifndef celem2d_h_
    #include "celem2d.h"
#endif
#ifndef cdiffusion2d_h_
    #include "cdiffusion2d.h"
#endif
#ifndef cgauss02_h_
    #include "cgauss02.h"
#endif

/* --------------------------------------------------------------------------- */

#ifndef mat3d11_h_
#define mat3d11_h_

void mat3d11 (celem2d *, cgauss02 *, Matrix3d &);
void mat3d11 (celem2d *, cgauss02 *, double (*)(double,double), Matrix3d &);
void mat3d11 (celem2d *, cgauss02 *, double, double (*)(double,double,double), Matrix3d &);
void mat3d11 (celem2d *, cgauss02 *, Matrix2d (*)(double,double), Matrix3d &);
void mat3d11 (celem2d *, cgauss02 *, double, Matrix2d (*)(double,double,double), Matrix3d &);
void mat3d11 (celem2d *, cgauss02 *, cdiffusion2d *, Matrix3d &);

#endif

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

