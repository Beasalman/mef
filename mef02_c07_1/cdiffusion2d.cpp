#include "cdiffusion2d.h"

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
// Matriz de difusión.

cdiffusion2d::cdiffusion2d () {}

/* ----------------------------------------------------------- */

cdiffusion2d::cdiffusion2d (double sigma, double rho, double nuinf) {
    
    this->sx2 = sigma * sigma;
    this->a11 = 0.5;
    this->a12 = 0.5 * rho * sigma  ;
    this->a22 = 0.5 * this->sx2 / nuinf;
}

/* ----------------------------------------------------------- */

Matrix2d cdiffusion2d::operator () (double x, double y) {}

/* ----------------------------------------------------------- */

Vector2d cdiffusion2d::divergenciaT (double x, double y) {}

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

