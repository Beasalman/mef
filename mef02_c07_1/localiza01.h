#include <iostream>
using std::cout;
using std::endl;
#include <vector>
#include <map>
using std::map;

#ifndef celem2d_h_
    #include "celem2d.h"
#endif
#ifndef cmalla2d01_h_
    #include "cmalla2d01.h"
#endif
#ifndef cnodo2d_h_
    #include "cnodo2d.h"
#endif

/* --------------------------------------------------------------------------- */

#ifndef localiza01_h_
#define localiza01_h_

celem2d* localiza01 (vector <cmalla2d01 *>, int, cnodo2d *);

#endif

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

