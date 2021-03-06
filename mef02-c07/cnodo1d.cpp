#include "cnodo1d.h"

/* --------------------------------------------------------------------------- */

cnodo1d::cnodo1d () {
    this->id = -1000;
    this->x = -1000.0;
}

/* --------------------------------------------------------------------------- */

cnodo1d::cnodo1d (int n) {
    this->id = n;
    this->x = -1000.0;    
}

/* --------------------------------------------------------------------------- */

cnodo1d::cnodo1d (int n, double x) {
    this->id = n;
    this->x = x;
}

/* --------------------------------------------------------------------------- */

void cnodo1d::print () {
    printf ("	%3d	%12.8f\n", this->id, this->x);
}

/* --------------------------------------------------------------------------- */

