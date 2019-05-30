#include <cmath>
using std::abs;

#include <vector>
using std::vector;

#include <stdexcept>
using std::overflow_error;

#ifndef celem2d_h_
    #include "celem2d.h"
#endif
#ifndef cnodo2d_h_
    #include "cnodo2d.h"
#endif


/* ------------------------------------------------------------------- */

#ifndef baric01_h_
#define baric01_h_

void baric01 (celem2d *, cnodo2d *, vector <double>);
void baric01 (celem2d *, cnodo2d *, cnodo2d *);

#endif

/* ------------------------------------------------------------------- */
