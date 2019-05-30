#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

#include <fstream>
using namespace std;

#include <map>
using std::map;

#ifndef cdatanum_h_
#define cdatanum_h_

/* -------------------------------------------------------------   */

class cdatanum {

    public:
        int tipoef;
        int caracniter;
        double caracdeltat;

        int pfniter;
        double pfemax;

        int metodosel;
        int niter;
        double eps;
        double omega;

        int kgauss;
        int nitp;
        int nitref;
        double theta;

        cdatanum ();
        void read (const char *);
        void print ();
};

#endif

/* -------------------------------------------------------------   */

