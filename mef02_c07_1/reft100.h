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

#ifndef reft100_h_
#define reft100_h_

void reft100 (cmalla2d01 *, 
              std::map <int, celem2d *> &, 
              std::map <int, carista *> &,
			  int i, int j, int k);

#endif

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

