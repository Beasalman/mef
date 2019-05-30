#include <iostream>
#include <stdio.h>
#include <vector>

#ifndef cnodo2d_h_
    #include "cnodo2d.h"
#endif

#ifndef cfrontera2d_h_
#define cfrontera2d_h_

/* -------------------------------------------------------------   */

class cfrontera2d {

    public:
        int id;
        std::vector <cnodo2d *> nodos;
		double dirich;

        /* -----------------------------------------------------   */

        cfrontera2d ();
        cfrontera2d (int);
        cfrontera2d (int, std::vector <cnodo2d *>);

        void print ();
};

/* -------------------------------------------------------------   */

#endif

/* -------------------------------------------------------------   */

