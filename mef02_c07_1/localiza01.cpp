#include "localiza01.h"

/* --------------------------------------------------------------------------- */

celem2d* localiza01 (vector <cmalla2d01 *> malla, int level, cnodo2d *p) {

    /* LOCALIZA: Localización del elemento de la malla que contiene a un punto.
                 En cada nivel se recorren los hijos del elemento que lo contiene.

       Entradas:
       - malla: lista de mallas.
       - level: nivel actual.
       - p:     punto a localizar.

       Salidas:
       - elem: elemento de la propia malla que contiene al punto P.
    */

    // ----------------------------------------------------------------------
    // Construcción del vector auxiliar (elementos de la primera malla).

    celem2d * elt;
    vector <celem2d *> aux;
    for (int i=0; i<malla[0]->auxelt.size(); i++) {
        aux.push_back (malla[0]->eltos[i]);
    }
    int naux = aux.size ();

    // ----------------------------------------------------------------------
    // Bucle sobre los niveles.

    // *************************************************************************************
    //cout << " [LOCALIZA01] Entramos en la función" << endl;
    //cout << " [LOCALIZA01]     level: " << level << endl;
    //cout << " [LOCALIZA01]     len(malla): " << malla.size() << endl;
    //cout << " [LOCALIZA01]        aux: ";
    //for (int i=0; i<naux; i++) {
    //    cout << " " << aux[i]->id;
    //}
    //cout << endl;
    // *************************************************************************************

    int j;
    int k = 0;
    while (k <= level) {

        // *************************************************************************************
        //cout << endl;
        //cout << " [LOCALIZA01]          k: " << k << " " << "        level: " << level << " ";
        //cout << "       hijos: ";
        //for (j=0; j<naux; j++) {
        //    cout << " (" << aux[j]->id << ", " << aux[j]->contains(p) << ")";
        //}
        //cout << "     ";
        // *************************************************************************************

        for (j=0; j<naux; j++) {
            // *************************************************************************************
            //cout << " elto: " << aux[j]->id << "   contains: " << aux[j]->contains (p);
            // *************************************************************************************
            if (aux[j]->contains (p)) {
                elt = aux[j];

                // Reconstrucción del vector auxiliar (hijos del elemento que contiene al punto).

                aux.clear ();
                for (int i=0; i<elt->hijos.size(); i++) {
                    aux.push_back (elt->hijos[i]);
                }
                naux = aux.size ();

                // *************************************************************************************
                //cout << "      aux: ";
                //for (int i=0; i<naux; i++) {
                //    cout << " " << aux[i]->id;
                //}
                //cout << endl;
                // *************************************************************************************

                k += 1;
                break;
            }
        }
        // *************************************************************************************
        //cout << endl;
        // *************************************************************************************
    }

    // *************************************************************************************
    //cout << " [LOCALIZA01]     Nos vamos, elemento: " << aux[j]->id << endl;
    // *************************************************************************************

    return aux[j];
}

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

/*
    map <int, celem2d *>::iterator ielt;

    int k = 0;
    while (k < level) {
        for (ielt=malla[k]->eltos.begin(); ielt != malla[k]->eltos.end(); ielt++) {
            if (ielt->second->contains (p)) {
                k += 1;
                break;
            }
        }
    }
*/

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

/*
    celem2d *ief;

    int k = 0;
    int nn = ef->neighbors.size ();
    for (int i=0; i<nn; i++) {
        ief = ef->neighbors [i];
        if (ief->contains (&p)) {
            elem = ief;
            k = 1;
            break;
        }
    }

    if (k == 0) {
        for (int i=0; i<this->nelt; i++) {
            ief = this->eltos [i];
            if (ief->contains (&p)) {
                elem = ief;
                k = 2;
                break;
            }
        }
    }
*/

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */
