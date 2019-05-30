#include <iostream>
using std::cout;
#include <vector>
using std::vector;

#include <Eigen/Dense>
#include <Eigen/Sparse>
using namespace Eigen;

#ifndef celem2d_h_
    #include "celem2d.h"
#endif
#ifndef cgauss02_h_
    #include "cgauss02.h"
#endif
#ifndef cmalla2d01_h_
    #include "cmalla2d01.h"
#endif
#ifndef csecond_h_
    #include "csecond.h"
#endif
#ifndef ensamb30_h_
    #include "ensamb30.h"
#endif
#ifndef mat3d11_h_
    #include "mat3d11.h"
#endif
#ifndef mat3d12_h_
    #include "mat3d12.h"
#endif
#ifndef vec3d11_h_
    #include "vec3d11.h"
#endif

/* --------------------------------------------------------------------------- */

#ifndef globalvec11_h_
#define globalvec11_h_

void globalvec11 (cmalla2d01 *, cgauss02 *, csecond *, VectorXd &, double);
void globalvec11 (cmalla2d01 *, cgauss02 *, csecond *, VectorXd &);

#endif

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

