#include <fstream>
#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::setprecision;
using std::setw;

/* ------------------------------------------------------------------------------------ */

#ifndef canalitica2d_h_
    #include "canalitica2d.h"
#endif
#ifndef cmalla2d01_h_
    #include "cmalla2d01.h"
#endif

/* ------------------------------------------------------------------------------------ */

#ifndef fprint12_h_
#define fprint12_h_

void fprint12 (int, cmalla2d01 *, canalitica2d *);
void fprint12 (int, int, cmalla2d01 *, canalitica2d *);
void fprint12 (int, cmalla2d01 *, double (*)(double,double));
void fprint12 (int, cmalla2d01 *, double, double (*)(double,double,double));
void fprint12 (int, cmalla2d01 *, double (*)(double,double), VectorXd &);
void fprint12 (int, int, cmalla2d01 *, double (*)(double,double), VectorXd &);
void fprint12 (int, cmalla2d01 *, double, double (*)(double,double,double), VectorXd &);

#endif

/* ------------------------------------------------------------------------------------ */

