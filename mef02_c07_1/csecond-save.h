#include <Eigen/Dense>
using namespace Eigen;

/* ----------------------------------------------------------------------- */

#ifndef csecond02_h_
#define csecond02_h_

class csecond02 {

    private:
        double sx;
        double sy;
        double rho;
        double r;                 // R
        double rsmall;            // r
        double q;
        double kappa;
        double hinf;
        double f;

        double sx2;
        double c2sx2;
        double c2sy2h2;
        double c2rsxsyh;
        double csx2rq;
        double k1r;

    public:
        csecond02 ();
        csecond02 (double, double, double, double, double, double, double, double, double);
        double operator () (double, double, double);
};

#endif

/* ----------------------------------------------------------------------- */
