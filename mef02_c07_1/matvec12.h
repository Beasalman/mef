#include <iostream>
using std::cout;
#include <vector>
using std::vector;

#include <Eigen/Dense>
#include <Eigen/Sparse>
using namespace Eigen;

#ifndef cdatanum_h_
    #include "cdatanum.h"
#endif
#ifndef celem2d_h_
    #include "celem2d.h"
#endif
#ifndef cgauss02_h_
    #include "cgauss02.h"
#endif
#ifndef cmalla2d01_h_
    #include "cmalla2d01.h"
#endif
#ifndef csecond01_h_
    #include "csecond01.h"
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

#ifndef matvec12_h_
#define matvec12_h_

void matvec12 (cmalla2d01 *, cgauss02 *, double, double, csecond01 *, SparseMatrix<double> &, VectorXd &);

#endif

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

