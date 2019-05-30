#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::setprecision;
using std::setw;

#ifndef ccurve_h_
    #include "ccurve.h"
#endif
#ifndef celem1d_h_
    #include "celem1d.h"
#endif
#ifndef cmalla1d_h_
    #include "cmalla1d.h"
#endif
#ifndef cnodo1d_h_
    #include "cnodo1d.h"
#endif
#ifndef cgauss1d_h_
    #include "cgauss1d.h"
#endif
#ifndef cvelocity1d_h_
    #include "cvelocity1d.h"
#endif

/* ------------------------------------------------------------ */

#ifndef carac1d_h_
#define carac1d_h_

void carac1d (cmalla1d *, cgauss1d *, cvelocity1d *, ccurve *, vector<double> &, vector<celem1d *> &);

#endif

/* ------------------------------------------------------------ */

