#include <iostream>
using std::cout;
using std::endl;

#include <map>
using std::map;

#ifndef carista_h_
    #include "carista.h"
#endif
#ifndef cnodo2d_h_
    #include "cnodo2d.h"
#endif
#ifndef cmalla2d01_h_
    #include "cmalla2d01.h"
#endif

#ifndef remesh04_h_
#define remesh04_h_

/* --------------------------------------------------------------------------- */

void remesh04 (cmalla2d01 *, map <int, cnodo2d *> &, map <int, carista *> &);

/* --------------------------------------------------------------------------- */

#endif
