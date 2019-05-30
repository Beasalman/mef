#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <Eigen/Dense>
using namespace Eigen;

#ifndef celem1d_h_
    #include "celem1d.h"
#endif
#ifndef cmalla1d_h_
    #include "cmalla1d.h"
#endif
#ifndef cgauss1d_h_
    #include "cgauss1d.h"
#endif
#ifndef elvec1d2gdl02_h_
    #include "elvec1d2gdl02.h"
#endif
#ifndef ensvec_h_
    #include "ensvec.h"
#endif

/* --------------------------------------------------------------------------- */

#ifndef globalvec02_h_
#define globalvec02_h_

void globalvec02 (cmalla1d *, cgauss1d *, vector <double>, vector <celem1d *>, VectorXd, VectorXd &);

#endif

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

