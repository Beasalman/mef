#include "ccall.h"

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

ccall::ccall (double E, double r, double D0, double mu, double sigma) {

    this->E = E;
    this->r = r;
    this->D0 = D0;
    this->mu = mu;
    this->sigma = sigma;
    this->rds1 = r - D0 + 0.5*sigma*sigma;
    this->rds2 = r - D0 - 0.5*sigma*sigma;
}

/* ----------------------------------------------------------- */

double ccall::operator () (double S, double tau, cnormal f) {

    double z;
    
    double a1 = log (S/this->E);
    double a2 = this->sigma * sqrt (tau);

    double d1 = (a1 + this->rds1 * tau) / a2;
    double d2 = (a1 + this->rds2 * tau) / a2;

    double k1 = trapn (d1, f);
    double k2 = trapn (d2, f);

    z = S * exp (-this->D0 * tau) * k1 - this->E * exp (-this->r * tau) * k2;

    return z;
}

/* ----------------------------------------------------------- */

VectorXd ccall::operator () (map <int,cnodo2d *> nodos, double tau, cnormal f) {

    VectorXd v (nodos.size());
    map <int, cnodo2d*> :: iterator inod;
    int i;
    double S, a1, a2, d1, d2, k1, k2;
    
    for (inod=nodos.begin(); inod!=nodos.end(); inod++) {
        i = inod->second->id;
        S = inod->second->x;

        a1 = log (S/this->E);
        a2 = this->sigma * sqrt (tau);

        d1 = (a1 + this->rds1 * tau) / a2;
        d2 = (a1 + this->rds2 * tau) / a2;

        k1 = trapn (d1, f);
        k2 = trapn (d2, f);

        v(i) = S * exp (-this->D0 * tau) * k1 - this->E * exp (-this->r * tau) * k2;
    }

    return v;
}

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
