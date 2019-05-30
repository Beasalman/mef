#include "remesh02.h"

/* --------------------------------------------------------------------------- */

void remesh02 (cmalla2d01 *m) {

    /* Refinamiento de mallado: 
       marcado de nuevos elementos y aristas para asegurar la conformidad.

    Entradas:
    - m:  (puntero a) malla.
    */

    /* ----------------------------------------------------------------------- */

    celem2d *ef;
    map <int, celem2d *> :: iterator ie;

    /* ----------------------------------------------------------------------- */

    int news = 1;
    while (news > 0) {
        news = 0;
        for (ie=m->eltos.begin(); ie!=m->eltos.end(); ie++) {
            ef = ie->second;

            // **************************************************************************
            //cout << "     [REMESH02]     Elemento " << ef->id << "   " << ef->aristas[0]->mark 
            //                                              << " " << ef->aristas[1]->mark << " " << ef->aristas[2]->mark << endl;
            // **************************************************************************
            
            if ((ef->aristas[1]->mark == 1 || ef->aristas[2]->mark == 1) && ef->aristas[0]->mark == 0) {
                // **************************************************************************
                //cout << "     [REMESH02]         Elemento " << ef->id << endl;
                // **************************************************************************
                ef->aristas[0]->mark = 1;
	
            }
            if (ef->aristas[1]->mark == 1 && ef->aristas[2]->mark == 1 && ef->aristas[0]->mark == 0) {
                ef->aristas[0]->mark = 1;

            }
        }

        // Marcamos el elemento.

        for (ie=m->eltos.begin(); ie!=m->eltos.end(); ie++) {
            ef = ie->second;
            int a = ef->aristas[0]->mark + ef->aristas[1]->mark + ef->aristas[2]->mark;
            if (a > 0 && ef->mark == 0) {
                news += 1;
                ef->mark = 1;
                ef->aristas[0]->mark = 1;
            }
        }
    }

    // **************************************************************************
    //cout << " [REMESH02]       Al salir de REMESH02:" << endl;
    //ef = m->eltos[6];
    //cout << " [REMESH02]          Elemento " << ef->id << "   " << ef->aristas[0]->id 
    //                                                     << " " << ef->aristas[1]->id << " " << ef->aristas[2]->id << endl;
    //ef = m->eltos[12];
    //cout << " [REMESH02]          Elemento " << ef->id << "   " << ef->aristas[0]->id 
    //                                                     << " " << ef->aristas[1]->id << " " << ef->aristas[2]->id << endl;
    //cout << endl;
    //for (ie=m->eltos.begin(); ie!=m->eltos.end(); ie++) {
    //    ef = ie->second;
    //    cout << " [REMESH02]          Elemento " << ef->id << "   " << ef->aristas[0]->mark 
    //                                                       << " " << ef->aristas[1]->mark << " " << ef->aristas[2]->mark << endl;
    //}
    // **************************************************************************

    /* ----------------------------------------------------------------------- */

    return;
}

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

