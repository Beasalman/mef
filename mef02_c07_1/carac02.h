#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <map>
using std::map;

#include <Eigen/Dense>
using namespace Eigen;

#ifndef cconv00_h_
    #include "cconv00.h"
#endif
#ifndef cmalla2d01_h_
    #include "cmalla2d01.h"
#endif
#ifndef cnodo2d_h_
    #include "cnodo2d.h"
#endif
#ifndef localiza00_h_
    #include "localiza00.h"
#endif

/* --------------------------------------------------------------------------- */

#ifndef carac02_h_
#define carac02_h_

// cnodo2d carac02 (cnodo2d *, double, int, vector <double>, cmalla2d01 *);
// cnodo2d carac02 (cnodo2d *, double, int, vector <double> (*)(double,double), cmalla2d01 *);
// cnodo2d carac02 (cnodo2d *, double, int, double, vector <double> (*)(double,double,double), cmalla2d01 *);
cnodo2d* carac02 (Vector2d, double, int, cconvection2d *, cmalla2d01 *);

#endif

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

