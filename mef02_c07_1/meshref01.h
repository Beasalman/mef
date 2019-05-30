#include <iostream>
using std::cout;

#include <vector>
using std::vector;

#include <map>
using std::map;

#ifndef celem2d_h_
    #include "celem2d.h"
#endif
#ifndef cfrontera2d_h_
    #include "cfrontera2d.h"
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
#ifndef remesh02_h_
    #include "remesh02.h"
#endif
#ifndef remesh03_h_
    #include "remesh03.h"
#endif
#ifndef remesh04_h_
    #include "remesh04.h"
#endif

/* --------------------------------------------------------------------------- */

#ifndef meshref01_h_
#define meshref01_h_

void meshref01 (cmalla2d01 *, map <int, cnodo2d *> &, map <int, celem2d *> &, map <int, carista *> &, int, double, cmark *);

#endif

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

