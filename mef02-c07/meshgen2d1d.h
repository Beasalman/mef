#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <set>
using std::set;

#ifndef celem1d_h_
    #include "celem1d.h"
#endif
#ifndef celem2d_h_
    #include "celem2d.h"
#endif
#ifndef cfrontera1d_h_
    #include "cfrontera1d.h"
#endif
#ifndef cfrontera2d_h_
    #include "cfrontera2d.h"
#endif
#ifndef cmalla1d_h_
    #include "cmalla1d.h"
#endif
#ifndef cmalla2d01_h_
    #include "cmalla2d01.h"
#endif
#ifndef cnodo1d_h_
    #include "cnodo1d.h"
#endif
#ifndef cnodo2d_h_
    #include "cnodo2d.h"
#endif

/* --------------------------------------------------------------------------- */

#ifndef meshgen2d1d_h_
#define meshgen2d1d_h_

cmalla1d *meshgen2d1d (cmalla2d01 *);

#endif

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

