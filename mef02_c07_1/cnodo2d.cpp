#include <vector>
#include "cnodo2d.h"

/* ---------------------------------------------------------------------- */

cnodo2d::cnodo2d () {
	id = -1000;
	x = -1000.0;
	y = -1000.0;
    w = 0.0;

//    north = NULL;
//    south = NULL;
//    east = NULL;
//    west = NULL;

    std::vector <cnodo2d *> v1nodos;
};

/* ---------------------------------------------------------------------- */

cnodo2d::cnodo2d (int n) {
	id = n;
	x = -1000.0;
	y = -1000.0;
    w = 0.0;

//    north = NULL;
//    south = NULL;
//    east = NULL;
//    west = NULL;

    std::vector <cnodo2d *> v1nodos;
};

/* ---------------------------------------------------------------------- */

cnodo2d::cnodo2d (int n, double xx, double yy) {
	id = n;
	x = xx;
	y = yy;
    w = 0.0;

//    north = NULL;
//    south = NULL;
//    east = NULL;
//    west = NULL;

    std::vector <cnodo2d *> v1nodos;
};

/* ---------------------------------------------------------------------- */

cnodo2d::cnodo2d (int n, double xx, double yy, double ww) {
	id = n;
	x = xx;
	y = yy;
    w = ww;

//    north = NULL;
//    south = NULL;
//    east = NULL;
//    west = NULL;

    std::vector <cnodo2d *> v1nodos;
};

/* ---------------------------------------------------------------------- */

void cnodo2d::print () {
	printf ("     %3d   %12.8f   %12.8f\n", this->id, this->x, this->y);
};

/* ---------------------------------------------------------------------- */

