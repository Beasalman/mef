#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <Eigen/Dense>
#include <Eigen/Sparse>
using namespace Eigen;

#ifndef celem1d_h_
    #include "celem1d.h"
#endif
#ifndef cdatanum_h_
    #include "cdatanum.h"
#endif
#ifndef cdataprob_h_
    #include "cdataprob.h"
#endif
#ifndef cmalla1d_h_
    #include "cmalla1d.h"
#endif
#ifndef cgauss1d_h_
    #include "cgauss1d.h"
#endif
#ifndef elmat1d2gdl03_h_
    #include "elmat1d2gdl03.h"
#endif
#ifndef elmat1d2gdl02_h_
    #include "elmat1d2gdl02.h"
#endif
#ifndef ensmat_h_
    #include "ensmat.h"
#endif

/* --------------------------------------------------------------------------- */

#ifndef globalmat02_h_
#define globalmat02_h_

void globalmat02 (cmalla1d *, cgauss1d *, cdataprob, cdatanum, double, SparseMatrix <double> &);

#endif

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

