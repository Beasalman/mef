#include <math.h>
#include <cmath>
using std::abs;

#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <map>
using std::map;

#include <Eigen/Dense>
using namespace Eigen;

#ifndef carista_h_
    #include "carista.h"
#endif
#ifndef cnodo2d_h_
    #include "cnodo2d.h"
#endif

#ifndef celem2d_h_
#define celem2d_h_

/* ----------------------------------------------------------------------------------- */

class celem2d {

    public:

        int id;
        int mark;
        int tiporef;
        int nhijos;
        double jac;
        double area;
		double estimador;
        cnodo2d cdg;

        Matrix2d ck;
        Vector2d dk;

        vector <cnodo2d *> nodos;
        vector <carista *> aristas;
        map <int, celem2d *> vecinos;

//        vector <int> numhijos;
        vector <celem2d *> hijos;
        celem2d *padre;
        vector <cnodo2d *> nodosdesplazados;            // Coordenadas baricéntricas de los puntos desplazados sobre la característica.
        vector <celem2d *> eltosdesplazados;            // Elementos a los que pertenecen los nodos desplazados.
        vector <celem2d *> neighbors;

//        vector <vector <double> > normales (3, vector <double> (2));           // Esto me da problemas, incluso sin utilizarlo posteriormente.
////        vector <double> v01;
////        vector <double> v02;
////        vector <double> v03;

        /* --------------------------------------------------------------------------- */

        celem2d ();
        celem2d (int n);
        celem2d (int n, cnodo2d *, cnodo2d *, cnodo2d *);
        celem2d (int n, cnodo2d *, cnodo2d *, cnodo2d *, cnodo2d *);
        celem2d (int n, cnodo2d *a, cnodo2d *b, cnodo2d *c, carista *p, carista *q, carista *r);

        void sort ();
        void superficie ();
//        void vnormal ();
        void cdgcompute ();
        bool contains (cnodo2d *);
        void print01 ();
        void print02 ();
        void print03 ();
};

/* ----------------------------------------------------------------------------------- */

#endif

/* ----------------------------------------------------------------------------------- */

