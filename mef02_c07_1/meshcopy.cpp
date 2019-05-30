#include "meshcopy.h"

/* -------------------------------------------------------------------------------------------- */

void meshcopy (cmalla2d01 *m, cmalla2d01 *p) {

    /* MESHCOPY: Copia de una malla M en otra P.

    Entradas:
    - m: (puntero a) malla.

    Salidas:
    - p: (puntero a) malla.
    */

    int i;

    map <int, cnodo2d*> :: iterator inod;
    map <int, celem2d*> :: iterator ielt;
    //map <int, cnodo*> :: iterator inod;
    //map <int, celem*> :: iterator ielt;
    map <int, carista*> :: iterator iart;

    // Copia de los parámetros escalares.

    // *****************************************************************************
    //cout << " [MESHCOPY] Comenzamos a copiar" << endl;
    //cout << " [MESHCOPY]         m->id = " << m->id << endl;
    //cout << " [MESHCOPY]       m->nsom = " << m->nsom << endl;
    //cout << " [MESHCOPY]       m->nelt = " << m->nelt << endl;
    //cout << " [MESHCOPY]        m->nfr = " << m->nfr << endl;
    //cout << " [MESHCOPY]   m->naristas = " << m->naristas << endl;
    //cout << " [MESHCOPY]       m->tipo = " << m->tipo << endl;
    //inod = m->nodos.begin();
    //cout << " [MESHCOPY]   m->nodos.begin() = " << inod->first << endl;
    //inod = m->nodos.end();
    //cout << " [MESHCOPY]     m->nodos.end() = " << inod->first << endl;
    //cout << " [MESHCOPY]     m->nodos.size() = " << m->nodos.size() << endl;
    // *****************************************************************************

    p->id = m->id;
    p->nsom = m->nsom;
    p->nelt = m->nelt;
    p->nfr = m->nfr;
    p->naristas = m->naristas;
    p->tipo = m->tipo;

    // *****************************************************************************
    //cout << " [MESHCOPY] Hemos copiado los parámetros escalares" << endl;
    // *****************************************************************************

    // Copia de vectores y diccionarios.

    for (inod=m->nodos.begin(); inod!=m->nodos.end(); inod++) {
        p->nodos[inod->first] = inod->second;
    }
    for (ielt=m->eltos.begin(); ielt!=m->eltos.end(); ielt++) {
        p->eltos[ielt->first] = ielt->second;
    }
    for (iart=m->aristas.begin(); iart!=m->aristas.end(); iart++) {
        p->aristas[iart->first] = iart->second;
    }

    for (i=0; i<m->nfr; i++) {
        p->fronteras.push_back (m->fronteras[i]);
    }

//    for (i=0; i<t->nsom; i++) {
//        newnod = new cnodo (t->nodos[i]->id, t->nodos[i]->x, t->nodos[i]->y);
//        this->nodos[i] = newnod;
//    }
//    for (i=0; i<t->nelt; i++) {
//        newelt = new celem (t->eltos[i]->id, t->eltos[i]->nodos[0], t->eltos[i]->nodos[1], t->eltos[i]->nodos[2]);
//        this->eltos[i] = newelt;
//    }
//    for (i=0; i<t->naristas; i++) {
//        newart = new carista (t->aristas[i]->id, t->aristas[i]->nodos[0], t->aristas[i]->nodos[1]);
//        this->aristas[i] = newart;
//    }

//    nodart (t.nodart),                 // Creo que no es necesario.
//    fronteras (t.fronteras) 

    // *****************************************************************************
    //cout << " [MESHCOPY] Comprobamos el tablero NODOS:" << endl;
    //inod = p->nodos.begin();
    //cout << " [MESHCOPY]   this->nodos.begin() = " << inod->first << endl;
    //inod = p->nodos.end();
    //cout << " [MESHCOPY]     this->nodos.end() = " << inod->first << endl;
    //cout << " [MESHCOPY]     this->nodos.size() = " << p->nodos.size() << endl;
    // *****************************************************************************

}

/* -------------------------------------------------------------------------------------------- */

