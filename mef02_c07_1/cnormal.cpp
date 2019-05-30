#include "cnormal.h"

/* --------------------------------------------------------------------------- */

cnormal::cnormal () {

    this->mean = 0.0;
    this->std = 1.0;
    this->finteg = new csimpson1d ();
}

/* --------------------------------------------------------------------------- */

cnormal::cnormal (double mean, double std) {

    this->mean = mean;
    this->std = std;
    this->finteg = new csimpson1d ();
}

/* --------------------------------------------------------------------------- */

double cnormal::operator () (double x) {

    /* ----------------------------------------------------------------------------------------------
    Estoy intentando hacer que la variable "t0" sea un atributo de las instancias.  Pero no me deja ...
    ---------------------------------------------------------------------------------------------- */

    double z;
    double t0 = -5.0;

    if (x < t0) {
        z = 0.0;
    } else {
        int n = 401;
        double h = (x - t0) / (n-1);
        double tt;

        VectorXd t (n);
        VectorXd y (n);
        for (int i=0; i<n; i++) {
            tt = t0 + i * h;
            t (i) = tt;
            y (i) = exp (-0.5 * pow(tt-this->mean, 2) / this->std);
        }
        z = (*this->finteg) (t, y) / (this->std * sqrt (2.0 * M_PI));
    }

    return z;
}

/* --------------------------------------------------------------------------- */

