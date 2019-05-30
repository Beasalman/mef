#include <vector>
#include "cfrontera2d.h"

/* ---------------------------------------------------------------------- */

cfrontera2d::cfrontera2d () {
	id = -1000;
};

/* ---------------------------------------------------------------------- */

cfrontera2d::cfrontera2d (int n) {
	id = n;
};

/* ---------------------------------------------------------------------- */

cfrontera2d::cfrontera2d (int n, std::vector <cnodo2d *> nods) {
	id = n;
    for (int i=0; i<nods.size(); i++) {
        nodos.push_back (nods[i]);
    }
};

/* ---------------------------------------------------------------------- */

void cfrontera2d::print () {
    printf ("   %d:      ", this->id);
    for (int i=0; i<this->nodos.size(); i++) {
        printf ("%4d ", this->nodos[i]->id);
    }
    printf ("\n");


//    printf ("     %3d   %12.8f   %12.8f\n", this->id, this->x, this->y);
};

/* ---------------------------------------------------------------------- */

/*
printf ("\nFronteras:\n");
for (int k=0; k<4; k++) {
    printf ("   %d:      ", k);
    for (int i=0; i<this->fronteras[k]->nodos.size(); i++) {
        printf ("%4d ", this->fronteras[k]->nodos[i]->id);
    }
    printf ("\n");
}
*/
