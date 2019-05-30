#include <iostream>
using std::cout;
using std::endl;

/* ----------------------------------------------------------------------------------- */

#ifndef cnodo2d_h_
    #include "cnodo2d.h"
#endif

/* ----------------------------------------------------------------------------------- */

#ifndef cdomain2d_h_
#define cdomain2d_h_

class cdomain2d {

    public:

        cnodo2d *vii;
        cnodo2d *vsd;

        cdomain2d (cnodo2d *, cnodo2d *);

        bool contains (cnodo2d *);
};

#endif

/* ----------------------------------------------------------------------------------- */

