#include <iostream>
using std::cout;
using std::fixed;

#include <vector>
using std::vector;

#include <map>
using std::map;

#include <Eigen/Dense>
#include <Eigen/Sparse>
#include <Eigen/SparseLU>
using namespace Eigen;

/* --------------------------------------------------------------------------- */

#ifndef baric01_h_
    #include "baric01.h"
#endif
#ifndef carac02_h_
    #include "carac02.h"
#endif
#ifndef cbs_h_
    #include "cbs.h"
#endif
#ifndef cconvection2d_h_
    #include "cconvection2d.h"
#endif
#ifndef cdatamesh_h_
    #include "cdatamesh.h"
#endif
#ifndef cdatanum_h_
    #include "cdatanum.h"
#endif
#ifndef cdataprob_h_
    #include "cdataprob.h"
#endif
#ifndef cdiffusion2d_h_
    #include "cdiffusion2d.h"
#endif
#ifndef cdomain2d_h_
    #include "cdomain2d.h"
#endif
#ifndef celem2d_h_
    #include "celem2d.h"
#endif
#ifndef cfrontera2d_h_
    #include "cfrontera2d.h"
#endif
#ifndef cgauss02_h_
    #include "cgauss02.h"
#endif
#ifndef cmalla2d01_h_
    #include "cmalla2d01.h"
#endif
#ifndef cmark_h_
    #include "cmark.h"
#endif
#ifndef cnodo2d_h_
    #include "cnodo2d.h"
#endif
#ifndef dirichlet22_h_
    #include "dirichlet22.h"
#endif
#ifndef error02_h_
    #include "error02.h"
#endif
#ifndef fprint11_h_
    #include "fprint11.h"
#endif
#ifndef fprint17_h_
    #include "fprint17.h"
#endif
#ifndef globalmat14_h_
    #include "globalmat14.h"
#endif
#ifndef globalvec11_h_
    #include "globalvec11.h"
#endif
#ifndef globalvec12_h_
    #include "globalvec12.h"
#endif
#ifndef globalvec13_h_
    #include "globalvec13.h"
#endif
#ifndef localiza01_h_
    #include "localiza01.h"
#endif
#ifndef matvec11_h_
    #include "matvec11.h"
#endif
#ifndef positive_h_
    #include "positive.h"
#endif
#ifndef util02_h_
    #include "util02.h"
#endif

/* --------------------------------------------------------------------------- */

#ifndef optioneuro00_h_
#define optioneuro00_h_

void optioneuro00 (vector <cmalla2d01 *>, int, cmalla2d01 *, cgauss02 *, cdataprob, cdatamesh, cdatanum, 
                   map <int, celem2d *>, map <int, cnodo2d *>, map <int, carista *>, cbs *, cmark *,
                   VectorXd &, cdiffusion2d *, cconvection2d *, cconvection2d *);

#endif

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

