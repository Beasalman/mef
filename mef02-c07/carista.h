#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

#ifndef cfrontera2d_h_
	#include "cfrontera2d.h"
#endif
#ifndef cnodo2d_h_
	#include "cnodo2d.h"
#endif

#ifndef carista_h_
#define carista_h_

/* --------------------------------------------------------------------- */

class carista {

    public:
        int id;
        int mark;
        int tipo;                  // 0: exterior,   1: interior (por defecto).
        cfrontera2d *frontera;     // frontera a la que pertenece.
        cnodo2d *nodohijo;

        // Vector para almacenar los punteros de los nodos

        std::vector <cnodo2d *> nodos;

        /* ------------------------------------------------------------- */

        carista ();
        carista (int n, cnodo2d *a, cnodo2d *b);
        double length ();
        void print ();
        void printn ();
};

/* --------------------------------------------------------------------- */

#endif

/* --------------------------------------------------------------------- */

