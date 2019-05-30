#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <map>
using std::map;

#ifndef carac01_h_
    #include "carac01.h"
#endif
#ifndef carac02_h_
    #include "carac02.h"
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

#ifndef carac00_h_
#define carac00_h_

cnodo2d carac00 (cnodo2d *, double, int, vector <double>, cmalla2d01 *);
cnodo2d carac00 (cnodo2d *, double, int, vector <double> (*)(double,double), cmalla2d01 *);
cnodo2d carac00 (cnodo2d *, double, int, double, vector <double> (*)(double,double,double), cmalla2d01 *);

#endif

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

