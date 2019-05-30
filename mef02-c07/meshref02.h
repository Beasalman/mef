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
#include <Eigen/SparseQR>
#include <Eigen/IterativeLinearSolvers>
using namespace Eigen;

/* --------------------------------------------------------------------------- */

#ifndef baric01_h_
    #include "baric01.h"
#endif
#ifndef carac02_h_
    #include "carac02.h"
#endif
#ifndef carista_h_
    #include "carista.h"
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
#ifndef celem2d_h_
    #include "celem2d.h"
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
#ifndef dirichlet20_h_
    #include "dirichlet20.h"
#endif
#ifndef dirichlet22_h_
    #include "dirichlet22.h"
#endif
#ifndef dirichlet22z_h_
    #include "dirichlet22z.h"
#endif
#ifndef globalmat13_h_
    #include "globalmat13.h"
#endif
#ifndef localiza01_h_
    #include "localiza01.h"
#endif
#ifndef meshref01_h_
    #include "meshref01.h"
#endif
#ifndef prolong_h_
    #include "prolong.h"
#endif
#ifndef util02_h_
    #include "util02.h"
#endif

/* --------------------------------------------------------------------------- */

#ifndef meshref02_h_
#define meshref02_h_

void meshref02 (vector <cmalla2d01 *> &, int &, cgauss02 *, cdataprob, cdatamesh, cdatanum,
                map <int, celem2d *> &, map <int, cnodo2d *> &, map <int, carista *> &, cmark *,
                VectorXd &, VectorXd &, SparseMatrix <double> &, cconvection2d *, cconvection2d *, 
                cdiffusion2d *);

#endif

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

