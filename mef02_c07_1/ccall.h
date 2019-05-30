#include <map>
using std::map;

#include <cmath>
using std::sqrt;
using std::exp;
using std::log;

#include <Eigen/Dense>
using namespace Eigen;

// const double pi = 3.14159265;

#ifndef cnodo2d_h_
    #include "cnodo2d.h"
#endif
#ifndef cnormal_h_
    #include "cnormal.h"
#endif
#ifndef trapn_h_
    #include "trapn.h"
#endif

/* ----------------------------------------------------------------------- */

#ifndef ccall_h_
#define ccall_h_

class ccall {

    private:
        double E;
        double r;
        double D0;
        double mu;
        double sigma;
        double rds1;
        double rds2;

    public:
        ccall (double, double, double, double, double);        // Constructor.
        double operator () (double, double, cnormal);
        VectorXd operator () (map <int, cnodo2d*>, double, cnormal);
};

#endif

/* ----------------------------------------------------------------------- */
