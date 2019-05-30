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
#include <Eigen/IterativeLinearSolvers>
#include <Eigen/OrderingMethods>
using namespace Eigen;

/* --------------------------------------------------------------------------- */

#ifndef baric01_h_
    #include "baric01.h"
#endif
#ifndef bicgstab01_h_
    #include "bicgstab01.h"
#endif
#ifndef canalitica2d_h_
    #include "canalitica2d.h"
#endif
#ifndef carac1d_h_
    #include "carac1d.h"
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
#ifndef ccurve01_h_
    #include "ccurve01.h"
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
#ifndef cgauss1d_h_
    #include "cgauss1d.h"
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
#ifndef conjgr01_h_
    #include "conjgr01.h"
#endif
#ifndef csecond01_h_
    #include "csecond01.h"
#endif
#ifndef cvelocity1d_h_
    #include "cvelocity1d.h"
#endif
#ifndef cvelocity1d0_h_
    #include "cvelocity1d0.h"
#endif
#ifndef dirichlet00_h_
    #include "dirichlet00.h"
#endif
#ifndef dirichlet22_h_
    #include "dirichlet22.h"
#endif
#ifndef dirichlet22z_h_
    #include "dirichlet22z.h"
#endif
#ifndef error02_h_
    #include "error02.h"
#endif
#ifndef fprint11_h_
    #include "fprint11.h"
#endif
#ifndef fprint12_h_
    #include "fprint12.h"
#endif
#ifndef fprint13_h_
    #include "fprint13.h"
#endif
#ifndef fprint14_h_
    #include "fprint14.h"
#endif
#ifndef fprint15_h_
    #include "fprint15.h"
#endif
#ifndef fprint16_h_
    #include "fprint16.h"
#endif
#ifndef fprint19_h_
    #include "fprint19.h"
#endif
#ifndef fprint21_h_
    #include "fprint21.h"
#endif
#ifndef globalmat02_h_
    #include "globalmat02.h"
#endif
#ifndef globalmat13_h_
    #include "globalmat13.h"
#endif
#ifndef globalvec02_h_
    #include "globalvec02.h"
#endif
#ifndef globalvec03_h_
    #include "globalvec03.h"
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
#ifndef meshgen2d1d_h_
    #include "meshgen2d1d.h"
#endif
#ifndef meshref01_h_
    #include "meshref01.h"
#endif
#ifndef meshref02_h_
    #include "meshref02.h"
#endif
#ifndef negative_h_
    #include "negative.h"
#endif
#ifndef norm_h_
    #include "norm.h"
#endif
#ifndef positive_h_
    #include "positive.h"
#endif
#ifndef prolong_h_
    #include "prolong.h"
#endif
#ifndef util02_h_
    #include "util02.h"
#endif
#ifndef util03_h_
    #include "util03.h"
#endif

/* --------------------------------------------------------------------------- */

#ifndef optioneuro02_h_
#define optioneuro02_h_

void optioneuro02 (vector <cmalla2d01 *>, int, cmalla2d01 *, cgauss02 *, cgauss1d *,  cdataprob, cdatamesh, cdatanum, 
                   map <int, celem2d *>, map <int, cnodo2d *>, map <int, carista *>, cbs *, cmark *,
                   VectorXd &, VectorXd &, cdiffusion2d *, cconvection2d *, cconvection2d *);

#endif

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

