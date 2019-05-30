#include <iostream>
using std::cout;
using std::endl;

#include <cmath>
#include <vector>
using std::vector;

#ifndef cnodo1d_h_
    #include "cnodo1d.h"
#endif

/* ---------------------------------------------------------- */

#ifndef celem1d_h_
#define celem1d_h_

class celem1d {

    public:
        int id;
        double h;
        double xm;
        double jac;

        vector <cnodo1d *> nodos;

        celem1d ();
        celem1d (int);
        celem1d (int, cnodo1d *, cnodo1d *);

        void jacobiano ();
        void print ();
        bool contains (double);
};

#endif

/* ---------------------------------------------------------- */

