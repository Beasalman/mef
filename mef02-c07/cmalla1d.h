#include <algorithm>
using std::min;
using std::max;

#include <vector>
using std::vector;

#include <Eigen/Dense>
using namespace Eigen;

#ifndef celem1d_h_
    #include "celem1d.h"
#endif
#ifndef cnodo1d_h_
    #include "cnodo1d.h"
#endif
#ifndef cfrontera1d_h_
    #include "cfrontera1d.h"
#endif
#ifndef cvelocity1d_h_
    #include "cvelocity1d.h"
#endif

/* ----------------------------------------------------------------------------------------- */

#ifndef cmalla1d_h_
#define cmalla1d_h_

class cmalla1d {

    public:
        int id;
        int nsom;
        int nelt;
        int nfr;
        double arroba;
		
        vector<cnodo1d *> nodos;
        vector<celem1d *> eltos;
        vector<cfrontera1d *> fronteras;

        cmalla1d ();
        cmalla1d (int, int, int);
        cmalla1d (int, int, int, vector <double>);
        cmalla1d (int, int, int, vector<cnodo1d *>);
        cmalla1d (int, int, int, vector<cnodo1d *>, vector<celem1d *>);
        cmalla1d (const cmalla1d &);
		
        void save (vector<double>);
        void save (VectorXd);
        celem1d * locp (double, cvelocity1d *, celem1d *);
        void print ();
        void fprint01 (int);
        void fprint02 (int);
        void fprint03 (int);
        void fprint04 (int);
        void fprint05 (int);
};

#endif

/* ----------------------------------------------------------------------------------------- */

