#include <iostream>
using std::cout;
using std::endl;

#include <vector>
#include <map>
using std::map;

#ifndef carista_h_
    #include "carista.h"
#endif
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

#ifndef reft101_h_
#define reft101_h_

void reft101 (cmalla2d01 *, 
              map <int, celem2d *> &, 
              map <int, carista *> &,
			  int i, int j, int k);

#endif

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

