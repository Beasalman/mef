#include "cdomain2d.h"

/* --------------------------------------------------------------------------- */

cdomain2d::cdomain2d (cnodo2d *vii, cnodo2d *vsd) {

    this->vii = vii;
    this->vsd = vsd;
};

/* -------------------------------------------------------------- */

bool cdomain2d::contains (cnodo2d *nod) {

    double eps = 1.e-12;

    return (nod->x >= this->vii->x && nod->x <= this->vsd->x && nod->y >= this->vii->y && nod->y <= this->vsd->y);
}

/* -------------------------------------------------------------- */

