#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;

#include <utility>

#include <string>
using std::string;

#include <fstream>
#include <sstream>
using std::ifstream;
using std::istringstream;
using std::ios_base;

#include <iterator>
using std::istream_iterator;

#include <iomanip>
using std::setprecision;
using std::setw;

#include <vector>
using std::vector;
#include <map>
using std::map;

#ifndef carista_h_
	#include "carista.h"
#endif
#ifndef celem2d_h_
	#include "celem2d.h"
#endif
#ifndef cdomain2d_h_
	#include "cdomain2d.h"
#endif
#ifndef cfrontera2d_h_
	#include "cfrontera2d.h"
#endif
#ifndef cnodo2d_h_
	#include "cnodo2d.h"
#endif

#ifndef cmalla2d01_h_
#define cmalla2d01_h_

/* ----------------------------------------------------------------------------------- */

class cmalla2d01 {

    public:

	    int id;
		int nsom;
		int nelt;
		int nfr;
		int naristas;
        int tipo;

        cdomain2d *domain;
		map <int, cnodo2d *> nodos;
		map <int, celem2d *> eltos;
		map <int, carista *> aristas;
		vector <cfrontera2d *> fronteras;
		vector <celem2d *> auxelt;

//        cfrontera2d fr0;
//        cfrontera2d fr1;
//        cfrontera2d fr2;
//        cfrontera2d fr3;

        map <std::pair <int,int>, carista *> nodart;
//        std::map <cpar, carista *> nodart;

        // Hay que eliminarlos; ya los tenemos en CMORSE01.

//        std::vector <int> pcol;         // Puntero COLUMNA para almacenamiento Morse.
//        std::vector <int> plin;         // Puntero LINEA para almacenamiento Morse.

        /* --------------------------------------------------------------------------- */

        cmalla2d01 ();
        cmalla2d01 (int, int, int, int);
        cmalla2d01 (int, int, int, int, vector <cnodo2d *>);
        cmalla2d01 (int, int, int, int, vector <cnodo2d *>, vector <celem2d *>);
        cmalla2d01 (int, int, int, int, vector <cnodo2d *>, vector <celem2d *>, vector <carista *>);
        cmalla2d01 (const cmalla2d01 &);
//        cmalla2d01 (cmalla2d01 *);
        ~cmalla2d01 ();                  // Destructor.

		void gnodart ();
		void pnodart ();
		void print ();
		void fprint01 (int);
		void fprint02 (int);
		void printv1 ();
		void read01 (const char *, map <int, cnodo2d *> &, map <int, celem2d *> &, map <int, carista *> &);
		void read02 (const char *, map <int, cnodo2d *> &, map <int, celem2d *> &, map <int, carista *> &);
};

/* ----------------------------------------------------------------------------------- */

#endif

/* ----------------------------------------------------------------------------------- */

