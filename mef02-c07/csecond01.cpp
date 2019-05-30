#include "csecond01.h"

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

csecond01::csecond01 () {}

/* ------------------------------------------------------------------------- */

csecond01::csecond01 (canalitica2d *analyt, cdiffusion2d *diff, cconvection2d *velo, double) {

    this->analyt = analyt;
    this->diff = diff;
    this->velo = velo;
    this->f = f;
}

/* ------------------------------------------------------------------------- */

double csecond01::operator () (double x, double y, double t) {

    /* CSECOND01: Segundo miembro.

    Entradas:
    - x,y: 
    - t:   tiempo real.
    */

    double u = (*this->analyt) (x,y,t);
    double ut = this->analyt->derivt (x,y,t);
    Vector2d gradu = this->analyt->gradient (x,y,t);
    Matrix2d ggradu = this->analyt->gradgrad (x,y,t);

    Matrix2d a = (*this->diff) (x,y);
    Vector2d divaT = this->diff->divergenciaT (x,y);
    Vector2d b = (*this->velo) (x,y);

    // Método 1.

    double aux = a (0,0) * ggradu (0,0) + a (1,0) * ggradu (0,1) + a (0,1) * ggradu (1,0) + a (1,1) * ggradu (1,1);         // dot (a.T, ggradu), producto interior.

//    return -(divaT.dot (gradu) + aux);              // OK, problema estacionario.
    return ut + (divaT.dot (gradu) + aux);

    /*
    // Método 2.

    double x2 = x * x;
    double y2 = y * y;
    double ux = 1.0 - x;
    double uy = 1.0 - y;
    double t1 = t + 1.0;
    double z = ut;
    z += a(0,0) * y2 * uy * t1 * (2.0 - 6.0 * x) + a(0,1) * (2.0 - 3.0 * y) * y * t1 * (2.0 * x - 3.0 * x2);
    z += a(1,0) * (2.0 - 3.0 * x) * x * t1 * (2.0 * y - 3.0 * y2) + a(1,1) * x2 * ux * t1 * (2.0 - 6.0 * y2);
    return z;
    */

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */


    // Otra forma de escribir el segundo miembro.
    // Solo si:    Omega = (1,2) x (1,2);   ua = (x-1)(2-x)(y-1)(2-y);     diff = [0.5s1^2 x^2, 0.5 r s1 s2 / hinf x; 0.5 r s1 s2 / hinf, 0.5 s2^2 / hinf^2].

//    double z = -this->diff->a11 * 6.0 * x * (1.0 - x) * (y - 1.0) * (2.0 - y)
//               - this->diff->a12 * ((-2.0 + 6.0 * x - 3.0 * x*x) * (3.0 - 2.0 * y) + x * (3.0 - 2.0 * x) * (3.0 - 2.0 * y))
//               + this->diff->a22 * (x - 1.0) * (2.0 - x);
//    return z;

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

    // Otra forma de escribir el segundo miembro.
    // Solo si:    Omega = (1,2) x (1,2);   ua = (x-1)(2-x)(y-1)(2-y);     diff = [x, x; x, y].

//    double z = -(3.-2.*x)*(y-1.0)*(2.0-y) - 2.0*(x-1.)*(2.-x)*(3.-2.*y) - x * (-2.0)*(y-1.)*(2.-y) - 2.0 * x * (3.-2.*x)*(3.-2.*y) - y*(-2.0)*(x-1)*(2.-x);
//    return z;

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

    /*
    // Psi = -div (diff grad u)
    // Desarrollo de sus términos.

    double z = 0.0;
    z -= this->diff->sx2 * x * (1.0 - 2.0 * x) * y * (1.0 - y);
    z -= this->diff->a12 * x * (1.0 - x) * (1.0 - 2.0 * y);
    z += this->diff->sx2 * x*x * y * (1.0 - y);
    z -= 2.0 * this->diff->a12 * x * (1.0 - 2.0 * x) * (1.0 - 2.0 * y);
    z += 2.0 * this->diff->a22 * x * (1.0 - x);
    return z;
    */

}

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

