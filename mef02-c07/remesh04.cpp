#include "remesh04.h"

/* --------------------------------------------------------------------------- */

void remesh04 (cmalla2d01 *m, map <int, cnodo2d *> &gnodos, map <int, carista *> &garistas) {

    /* Refinamiento de mallado: 
          - creación de los nodos en las aristas marcadas
          - creación de las aristas que surgen por división de las aristas marcadas.

    Entradas:
    - m:        (puntero a) malla.
    - gnodos:   
    - garistas: 
    */




    /* ----------------------------------------------------------------------- */

    int i, j, k;
    int z;
    double xx, yy, ww;
    carista *a, *newart;
    cnodo2d *newnod;

    /* ----------------------------------------------------------------------- */

    j = gnodos.size ();
    k = garistas.size ();

    std::map <int, carista *>::iterator iart;
    for (iart=m->aristas.begin(); iart != m->aristas.end(); iart++) {
        a = iart->second;
//cout << " meshref04  Malla: " << m->id << " id arista : " << a->id << " \n";

    }
	
    for (iart=m->aristas.begin(); iart != m->aristas.end(); iart++) {
        a = iart->second;

        if (a->mark == 1) {
	//cout << " id arista : " << a->id << " \n";
//cout << " meshref04  Malla: " << m->id << " id arista mark1 : " << a->id << " \n";
            // Creamos el nuevo nodo.

            xx = 0.5 * (a->nodos[0]->x + a->nodos[1]->x);
            yy = 0.5 * (a->nodos[0]->y + a->nodos[1]->y);
            ww = 0.5 * (a->nodos[0]->w + a->nodos[1]->w);
            z = (int) ww;
            ww = z;

            newnod = new cnodo2d (j, xx, yy, ww);
            gnodos[j] = newnod;
            m->nodos[j] = newnod;
            a->nodohijo = newnod;
            newnod->aristamadre = a;
            j += 1;
            m->nsom += 1;


            // Creamos las dos nuevas aristas que surgen al subdividir la anterior.

            newart = new carista (k, newnod, a->nodos[0]);
            newart->tipo = a->tipo;
            newart->frontera = a->frontera;
            garistas[k] = newart;
            m->aristas[k] = newart;

            newart = new carista (k+1, newnod, a->nodos[1]);
            newart->tipo = a->tipo;
            newart->frontera = a->frontera;
            garistas[k+1] = newart;
            m->aristas[k+1] = newart;

            // Actualizamos la frontera, en el caso de una arista exterior.

            if (a->frontera != NULL) {
                a->frontera->nodos.push_back (newnod);

            }
	
            k += 2;
            m->naristas += 2;
        }

    }

    /* ----------------------------------------------------------------------- */
    // Borramos las aristas que acabamos de dividir.
	
//Inigo  violacion de segmento
   /* for (iart=m->aristas.begin(); iart != m->aristas.end(); iart++) {
        a = iart->second;
	std::cout << a->id<< " id  second\n";
	std::cout << iart->first<< " id \n";
	std::cout << a->id<< " id second\n";
	std::cout << m->naristas<< " aristas sin eliminar\n";
        if (a->mark == 1) {	
            m->aristas.erase (iart->first);
	
            m->naristas -= 1;
		iart ++;
 	std::cout << m->naristas<< " aristas finales \n";
        }
 
	
    }*/


	
   for (iart=m->aristas.begin(); iart != m->aristas.end(); ) {
        a = iart->second;
	/*std::cout << a->id<< " id  second\n";
	std::cout << iart->first<< " id \n";
	std::cout << a->id<< " id second\n";
	std::cout << m->naristas<< " aristas sin eliminar\n";*/
        if (a->mark == 1) {	
            m->aristas.erase (iart++);
	//std::cout << a->id<< " aristas eliminada \n";
            m->naristas -= 1;
		//iart ++;
 	/*std::cout << m->naristas<< " aristas finales \n";*/
        }
	else{
	 ++iart;	
	}
 
	
    }
	
//std::cout << m->id<< " id \n";
/*for (iart=m->aristas.begin(); iart != m->aristas.end(); iart++) {
        a = iart->second;
	std::cout << iart->first<< " id \n";
}*/
    /* ----------------------------------------------------------------------- */

    return;
}

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

