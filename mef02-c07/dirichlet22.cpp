#include "dirichlet22.h"

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

void dirichlet22 (cmalla2d01 *m, SparseMatrix <double> &a) {

    /* DIRICHLET22: Condiciones de contorno sobre todas las fronteras de la malla.
                    Problema bidimensional.
                    Matrices huecas.

    Entradas:
    - m: (puntero a) malla.

    Entrada/salida:
    - a: (puntero a) matriz.
    - b: (puntero a) segundo miembro.
    */

    int i, j, k;
    cfrontera2d *fr;
    cnodo2d *nod;

    double arroba = 1.e+15;

    // ---------------------------------------------------------------------------

    fr = m->fronteras [1];
    for (int i=0; i<fr->nodos.size(); i++) {
        nod = fr->nodos [i];
        k = nod->id;
        a.coeffRef (k,k) = arroba;
    }

    fr = m->fronteras [2];
    for (int i=0; i<fr->nodos.size(); i++) {
        nod = fr->nodos [i];
        k = nod->id;
        a.coeffRef (k,k) = arroba;
    }

    /*
    fr = m->fronteras [2];
    for (int i=0; i<fr->nodos.size(); i++) {
        nod = fr->nodos [i];
        k = nod->id;
        a.coeffRef (k,k) = arroba;
        b (k) = arroba * f (nod->x,nod->y);
    }
    */

    /*
    for (int j=0; j<m->fronteras.size(); j++) {
        fr = m->fronteras [j];
        for (int i=0; i<fr->nodos.size(); i++) {
            nod = fr->nodos [i];
            k = nod->id;
            a.coeffRef (k,k) = arroba;
            b (k) = arroba * f (nod->x,nod->y);
        }
    }
    */
}

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

void dirichlet22 (cmalla2d01 *m, VectorXd bk, VectorXd uold, double deltatau, double f, VectorXd &b) {

    /* DIRICHLET22: Condiciones de contorno sobre todas las fronteras de la malla.
                    Problema bidimensional.
                    Matrices huecas.

    Entradas:
    - m: (puntero a) malla.

    Entrada/salida:
    - b: (puntero a) segundo miembro.
    */

    int i, j, k;
    cfrontera2d *fr;
    cnodo2d *nod;
    celem2d *elt;

    double arroba = 1.e+15;
    double bc, b0, b1, b2;

    // ---------------------------------------------------------------------------

    fr = m->fronteras [1];
    for (int i=0; i<fr->nodos.size(); i++) {
        nod = fr->nodos [i];
        k = nod->id;
        b (k) = 0.0;
    }

    fr = m->fronteras [2];
    for (int i=0; i<fr->nodos.size(); i++) {
        nod = fr->nodos [i];
        
        elt = nod->eltodesplazado;
        b1 = nod->nododesplazado->x;
        b2 = nod->nododesplazado->y;
        b0 = 1.0 - b1 - b2;
        bc = b0 * uold (elt->nodos[0]->id) + b1 * uold (elt->nodos[1]->id) + b2 * uold (elt->nodos[2]->id);

        k = nod->id;
        b (k) = arroba * (deltatau * bk (k) + bc) / (1.0 + deltatau * f);
    }

    /*
    fr = m->fronteras [2];
    for (int i=0; i<fr->nodos.size(); i++) {
        nod = fr->nodos [i];
        k = nod->id;
        a.coeffRef (k,k) = arroba;
        b (k) = arroba * f (nod->x,nod->y);
    }
    */

    /*
    for (int j=0; j<m->fronteras.size(); j++) {
        fr = m->fronteras [j];
        for (int i=0; i<fr->nodos.size(); i++) {
            nod = fr->nodos [i];
            k = nod->id;
            a.coeffRef (k,k) = arroba;
            b (k) = arroba * f (nod->x,nod->y);
        }
    }
    */
}

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */
void dirichlet22 (cmalla2d01 *m, VectorXd v1d, VectorXd &b) {

    /* DIRICHLET22: Condiciones de contorno sobre todas las fronteras de la malla.
                    Problema bidimensional.
                    Matrices huecas.

    Entradas:
    - m: (puntero a) malla.

    Entrada/salida:
    - b: (puntero a) segundo miembro.
    */

    int i, j, k;
    cfrontera2d *fr;
    cnodo2d *nod;
    celem2d *elt;

    double arroba = 1.e+15;
    double bc, b0, b1, b2;

    // ---------------------------------------------------------------------------



    fr = m->fronteras [1];

    for (int i=0; i<fr->nodos.size(); i++) {
        nod = fr->nodos [i];
        k = nod->id;
        b (k) = arroba * v1d(k);
    }

    fr = m->fronteras [2];
    for (int i=0; i<fr->nodos.size(); i++) {
        nod = fr->nodos [i];
        k = nod->id;
        b (k) = arroba * v1d(k);
    }
    
    /*for (int i=0; i<fr->nodos.size(); i++) {
        nod = fr->nodos [i];
        
        elt = nod->eltodesplazado;
        b1 = nod->nododesplazado->x;
        b2 = nod->nododesplazado->y;
        b0 = 1.0 - b1 - b2;
        bc = b0 * uold (elt->nodos[0]->id) + b1 * uold (elt->nodos[1]->id) + b2 * uold (elt->nodos[2]->id);

        k = nod->id;
        b (k) = arroba * (deltatau * bk (k) + bc) / (1.0 + deltatau * f);
    }*/

    /*
    fr = m->fronteras [2];
    for (int i=0; i<fr->nodos.size(); i++) {
        nod = fr->nodos [i];
        k = nod->id;
        a.coeffRef (k,k) = arroba;
        b (k) = arroba * f (nod->x,nod->y);
    }
    */

    /*
    for (int j=0; j<m->fronteras.size(); j++) {
        fr = m->fronteras [j];
        for (int i=0; i<fr->nodos.size(); i++) {
            nod = fr->nodos [i];
            k = nod->id;
            a.coeffRef (k,k) = arroba;
            b (k) = arroba * f (nod->x,nod->y);
        }
    }
    */
}
/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

//void dirichlet22 (cmalla2d01 *m, MatrixXd v1d, VectorXd &b) {
// void dirichlet22 (cmalla2d01 *m, float *v1d, VectorXd &b) {
void dirichlet22 (cmalla2d01 *m, cmalla1d *m1d, VectorXd v1d_nu, VectorXd v1d_S, VectorXd &b) {

    /* DIRICHLET22: Condiciones de contorno sobre todas las fronteras de la malla.
                    Problema bidimensional.
                    Matrices huecas.

    Entradas:
    - m: (puntero a) malla.

    Entrada/salida:
    - b: (puntero a) segundo miembro.
    */

    int i, k, posfr;
    cfrontera2d *fr1, *fr2;
    cnodo2d *nod;
    celem2d *elt;

    double arroba = 1.e+15;
    double bc, b0, b1, b2, coordx;

    // ---------------------------------------------------------------------------

    fr1 = m->fronteras [1];
    fr2 = m->fronteras [2];
   
    for (int i=0; i<fr1->nodos.size(); i++) {
        nod = fr1->nodos [i];
        k = nod->id;
	// b (k) = arroba * v1d(i,fr2->nodos.size());
	//b (k) = arroba * v1d[i][fr2->nodos.size()];	
	b (k) = arroba * v1d_nu(i);
    }
cout << "   m1d->nsom =" << m1d->nsom  <<  endl ;   
	
cout << "   m1d->nodos.back()->x =" << m1d->nodos.back()->x <<   endl ;   
	
	double deltas = m1d->nodos.back()->x/(m1d->nsom-1);
	cout << "   deltas =" <<deltas<<   endl ;   

   
	for (int i=0; i<fr2->nodos.size(); i++)  {
	    nod = fr2->nodos [i];
	    k = nod->id;
	    coordx = nod->x;
	    posfr = coordx / deltas;
	
	cout << " \n posfr = " << posfr  << endl ;
	  
	    b (k) = arroba * v1d_S(posfr);
		
	    
        }
    
    
/* --------------------------------------------
	int j=0;
	for (int i=0; i<fr2->nodos.size(); i++) {
	    nod = fr2->nodos [i];
	    k = nod->id;
	cout << "  i= " << i << "  j= " << j << endl ;
	cout << " \n  nod->x= " << nod->x << "  m1d->nodos[j]->x= " << m1d->nodos[j]->x << endl ;
	    if (nod->x == m1d->nodos[j]->x){
		b (k) = arroba * v1d_S(j);
		cout << "   k = nod->id;=" << k << "  j= " << j << "  i= " << i << endl ;
		j+=1;
		
	    }
	    else{
		 j+=2;
		 
	    }
        }
----------------------------------------------------*/



    /*for (int i=0; i<fr->nodos.size(); i++) {
        nod = fr->nodos [i];
        
        elt = nod->eltodesplazado;
        b1 = nod->nododesplazado->x;
        b2 = nod->nododesplazado->y;
        b0 = 1.0 - b1 - b2;
        bc = b0 * uold (elt->nodos[0]->id) + b1 * uold (elt->nodos[1]->id) + b2 * uold (elt->nodos[2]->id);

        k = nod->id;
        b (k) = arroba * (deltatau * bk (k) + bc) / (1.0 + deltatau * f);
    }*/

    /*
    fr = m->fronteras [2];
    for (int i=0; i<fr->nodos.size(); i++) {
        nod = fr->nodos [i];
        k = nod->id;
        a.coeffRef (k,k) = arroba;
        b (k) = arroba * f (nod->x,nod->y);
    }
    */

    /*
    for (int j=0; j<m->fronteras.size(); j++) {
        fr = m->fronteras [j];
        for (int i=0; i<fr->nodos.size(); i++) {
            nod = fr->nodos [i];
            k = nod->id;
            a.coeffRef (k,k) = arroba;
            b (k) = arroba * f (nod->x,nod->y);
        }
    }
    */
cout << "   Adios\n" ;
}
