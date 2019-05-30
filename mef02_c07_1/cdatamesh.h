#include <iostream>
using std::cout;
using std::endl;

#include <fstream>
using namespace std;

#include <map>
using std::map;

#ifndef cnodo2d_h_
    #include "cnodo2d.h"
#endif

#ifndef cdatamesh_h_
#define cdatamesh_h_

/* -------------------------------------------------------------   */

class cdatamesh {

    public:
        int tipomalla;
        int nref;
        int tref0;
        int tref1;
        double sigma;
        int nx;
        int ny;
        char *nomfic;
        cnodo2d vii;
        cnodo2d vsd;

        cdatamesh ();
        void read (const char *);
        void print ();
};

#endif

/* -------------------------------------------------------------   */

