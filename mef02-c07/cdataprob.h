#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

#include <fstream>
using namespace std;

#include <map>
using std::map;

#ifndef cdataprob_h_
#define cdataprob_h_

/* -------------------------------------------------------------   */

class cdataprob {

    public:
        int dominio;
        int second;
        int analitica;
        int tipodiff;
        int product;           // Tipo de producto.
        int option;            // Tipo de opción.
        int mtmarket;          // Mark-to-market.
        double tini;
        double tfin;
        double sigma;         // Volatilidad activo 1.
        double rho;            // Correlación.
        double RB;              // Tasa de recuperación.
        double RC;              // Tasa de recuperación.
        double r;              // Tasa de interés libre de riesgo.
        double rr;             // r_R.
        double theta0;          // 
        double kappa;          // 
        double nuinf;           // h máximo.
        double lambdaB;              // 
        double lambdaC;              // 
        double sF;              // 
        double strike;         // E, strike.
        double sinf;           // S máximo.

        cdataprob ();
        void read (const char *);
        void print ();
};

#endif

/* -------------------------------------------------------------   */

