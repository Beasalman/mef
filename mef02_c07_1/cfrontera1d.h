#include <stdio.h>

#ifndef cnodo1d_h_
    #include "cnodo1d.h"
#endif

/* ----------------------------------------------------------------------- */

#ifndef cfrontera1d_h_
#define cfrontera1d_h_

class cfrontera1d {

    public:
        int id;
        cnodo1d *nodo;
	
        cfrontera1d ();
        cfrontera1d (int);
        cfrontera1d (int, cnodo1d*);
    
        void print ();
};

#endif

/* ----------------------------------------------------------------------- */

