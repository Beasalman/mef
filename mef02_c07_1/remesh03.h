#include <algorithm>
using std::max;

#include <iostream>
using std::cout;
using std::endl;

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
#ifndef reft100_h_
    #include "reft100.h"
#endif
#ifndef reft101_h_
    #include "reft101.h"
#endif
#ifndef reft110_h_
    #include "reft110.h"
#endif
#ifndef reft111_h_
    #include "reft111.h"
#endif

#ifndef remesh03_h_
#define remesh03_h_

/* --------------------------------------------------------------------------- */

void remesh03 (cmalla2d01 *, map <int, celem2d *> &, map <int, carista *> &);

/* --------------------------------------------------------------------------- */

#endif
