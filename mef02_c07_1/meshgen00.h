#include <iostream>
using std::cout;
#include <vector>

#ifndef celem2d_h_
    #include "celem2d.h"
#endif
#ifndef cfrontera2d_h_
    #include "cfrontera2d.h"
#endif
#ifndef cmalla2d01_h_
    #include "cmalla2d01.h"
#endif
#ifndef cnodo2d_h_
    #include "cnodo2d.h"
#endif

/* --------------------------------------------------------------------------- */

#ifndef meshgen00_h_
#define meshgen00_h_

void meshgen00 (cmalla2d01 *, cnodo2d, cnodo2d, 
                std::map <int, cnodo2d *> &,
                std::map <int, celem2d *> &, 
                std::map <int, carista *> &);

#endif

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

