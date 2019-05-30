#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <map>
using std::map;

#ifndef cnodo2d_h_
    #include "cnodo2d.h"
#endif

/* --------------------------------------------------------------------------- */

#ifndef carac01_h_
#define carac01_h_

cnodo2d carac01 (cnodo2d *, double, int, vector <double>);
cnodo2d carac01 (cnodo2d *, double, int, vector <double> (*)(double,double));

#endif

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

