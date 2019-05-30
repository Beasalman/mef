#include "carista.h"

/* -------------------------------------------------------------- */

carista::carista () {

    id = -10;
    nodos.push_back(NULL);
    nodos.push_back(NULL);

    mark = 0;
    tipo = 1;       // Interior, por defecto.
    frontera = NULL;
    nodohijo = NULL;
};

/* -------------------------------------------------------------- */

carista::carista (int n, cnodo2d *a, cnodo2d *b) {

	// a y b son punteros a nodos.
	// Un puntero es la dirección de memoria en la que está el objeto. 
    // Almacenando la dirección, se pueden ver los cambios que hay en el objeto.

	id = n;
	nodos.push_back (a);
	nodos.push_back (b);

	mark = 0;
    tipo = 1;      // Interior, por defecto.
    frontera = NULL;
    nodohijo = NULL;
};

/* -------------------------------------------------------------- */

double carista::length () {

    double ax = this->nodos[0]->x - this->nodos[1]->x;
    double ay = this->nodos[0]->y - this->nodos[1]->y;

    return sqrt (ax * ax + ay * ay);
}

/* -------------------------------------------------------------- */

void carista::print () {

	printf ("     %3d        %4d  %4d       %4d\n",
			this->id,
			this->nodos[0]->id,
			this->nodos[1]->id,
			this->mark);
};

/* -------------------------------------------------------------- */

void carista::printn () {

    printf ("   Arista  %3d      Nodo %4d  (%12.8f,  %12.8f)\n                    Nodo %4d  (%12.8f, %12.8f)\n",
            this->id,
            this->nodos[0]->id, this->nodos[0]->x, this->nodos[0]->y,
            this->nodos[1]->id, this->nodos[1]->x, this->nodos[1]->y);
};

/* -------------------------------------------------------------- */

