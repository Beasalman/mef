#include "dirichlet22z.h"

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

void dirichlet22z (cmalla2d01 *m, SparseMatrix <double> &a) {

    /* DIRICHLET22z: Condiciones de contorno sobre todas las fronteras de la malla.
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

    fr = m->fronteras [0];
    for (int i=0; i<fr->nodos.size(); i++) {
        nod = fr->nodos [i];
        k = nod->id;
        //-- a.coeffRef (k,k) = arroba;
        for (int j=0; j<m->nsom; j++) a.coeffRef (k,j) = 0.0;
        a.coeffRef (k,k) = 1.0;
    }

    fr = m->fronteras [1];
    for (int i=0; i<fr->nodos.size(); i++) {
        nod = fr->nodos [i];
        k = nod->id;
        //-- a.coeffRef (k,k) = arroba;
        for (int j=0; j<m->nsom; j++) a.coeffRef (k,j) = 0.0;
        a.coeffRef (k,k) = 1.0;
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

void dirichlet22z (cmalla2d01 *m, VectorXd bk, VectorXd uold, double deltatau, double f, VectorXd &b) {

    /* DIRICHLET22z: Condiciones de contorno sobre todas las fronteras de la malla.
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

    fr = m->fronteras [0];
    for (int i=0; i<fr->nodos.size(); i++) {
        nod = fr->nodos [i];
        k = nod->id;

        // ************************************************************************
        //cout << " [DIRICHLET22Z]   Frontera: 0         Nodo: " << k << endl;
        // ************************************************************************

        b (k) = 0.0;
    }

    // ************************************************************************
    //cout << " [DIRICHLET22Z]   Frontera 1 tiene " << m->fronteras[1]->nodos.size() << " nodos: ";
    //for (int i=0; i<m->fronteras[1]->nodos.size(); i++) {
    //    cout << " " << m->fronteras[1]->nodos[i]->id;
    //}
    //cout << endl;
    // ************************************************************************

    fr = m->fronteras [1];
    for (int i=0; i<fr->nodos.size(); i++) {
        nod = fr->nodos [i];

        // ************************************************************************
        //cout << " [DIRICHLET22Z]   Frontera: 1            i: " << i;
        //cout << "    elt: " << nod->eltodesplazado->id;
        //cout << "     b1: " << nod->nododesplazado->x;
        //cout << "     b2: " << nod->nododesplazado->y;
        // ************************************************************************

        elt = nod->eltodesplazado;
        b1 = nod->nododesplazado->x;
        b2 = nod->nododesplazado->y;
        b0 = 1.0 - b1 - b2;
        bc = b0 * uold (elt->nodos[0]->id) + b1 * uold (elt->nodos[1]->id) + b2 * uold (elt->nodos[2]->id);

//        k = nod->id;
//
//        // ************************************************************************
//        cout << "      Nodo: " << k << endl;
//        cout << "     bk (k) = " << bk (k) << "     bc = " << bc << endl;
//        // ************************************************************************
//
//        //-- b (k) = arroba * (deltatau * bk (k) + bc) / (1.0 + deltatau * f);
//        b (k) = (deltatau * bk (k) + bc) / (1.0 + deltatau * f);

        // ************************************************************************
        //cout << "      Hemos dado valor a b (" << k << ")" << endl;
        // ************************************************************************
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

