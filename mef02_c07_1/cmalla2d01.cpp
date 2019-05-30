#include "cmalla2d01.h"

/* --------------------------------------------------------------------------- */
/* Clase CMALLA01.

   Los atributos NODOS y ELTOS son de tipo MAP.
   Conveniente para el refinamiento.                                           */
/* --------------------------------------------------------------------------- */

cmalla2d01::cmalla2d01 () {

    this->id = -1000;
    this->nsom = 0;
    this->nelt = 0;
    this->naristas = 0;
    this->nfr = 4;
    this->tipo = 0;
};

/* --------------------------------------------------------------------------- */

cmalla2d01::cmalla2d01 (int i, int ns, int ne, int nar) {

    this->id = i;
    this->nsom = ns;
    this->nelt = ne;
    this->naristas = nar;
    this->nfr = 4;
};

/* -------------------------------------------------------------- */

cmalla2d01::cmalla2d01 (int i, int ns, int ne, int nar, std::vector <cnodo2d *> nods) {

    this->id = i;
    this->nsom = ns;
    this->nelt = 0;
    this->naristas = 0;
    this->nfr = 4;

    // Almacenamos los nodos en un vector.

    for (int i=0; i<this->nsom; i++) {
        this->nodos[i] = nods[i];
//        this->nodos.push_back (nods[i]);
    }
};

/* -------------------------------------------------------------- */

cmalla2d01::cmalla2d01 (int i, int ns, int ne, int nar, std::vector <cnodo2d *> nods, std::vector <celem2d *> elts) {

    this->id = i;
    this->nsom = ns;
    this->nelt = ne;
    this->naristas = 0;
    this->nfr = 4;

    // Almacenamos los nodos en un vector.

    for (int i=0; i<this->nsom; i++) {
        this->nodos[i] = nods[i];
//        this->nodos.push_back (nods[i]);
    }

    // Almacenamos los elementos en otro vector.

    for (int i=0; i<this->nelt; i++) {
        this->eltos[i] = elts[i];
//        this->eltos.push_back (elts[i]);
    }
};

/* -------------------------------------------------------------- */

cmalla2d01::cmalla2d01 (int i, int ns, int ne, int nar, std::vector <cnodo2d *> nods, std::vector <celem2d *> elts, std::vector <carista *> arts) {

    this->id = i;
    this->nsom = ns;
    this->nelt = ne;
    this->naristas = nar;
    this->nfr = 4;

    // Almacenamos los nodos en un vector.

    for (int i=0; i<this->nsom; i++) {
        this->nodos[i] = nods[i];
//        this->nodos.push_back (nods[i]);
    }

    // Almacenamos los elementos en otro vector.

    for (int i=0; i<this->nelt; i++) {
        this->eltos[i] = elts[i];
//        this->eltos.push_back (elts[i]);
    }

    // Almacenamos las aristas en otro vector.

    for (int i=0; i<this->naristas; i++) {
        this->aristas[i] = arts[i];
//        this->aristas.push_back (arts[i]);
    }
};

/* -------------------------------------------------------------- */

cmalla2d01::cmalla2d01 (const cmalla2d01 &t)

    // Constructor copia.

    : id (t.id),
    nsom (t.nsom),
    nelt (t.nelt),
    nfr (t.nfr),
    naristas (t.naristas),
    tipo (t.tipo),
//    domain (t.domain),

    nodos (t.nodos),
    eltos (t.eltos),
    aristas (t.aristas),
    fronteras (t.fronteras),
    nodart (t.nodart),
    auxelt (t.auxelt)
{};

/* -------------------------------------------------------------- */

/*
cmalla2d01::cmalla2d01 (const cmalla2d01 &t) {

    // Constructor copia.

    id = t.id;
    nsom = t.nsom;
    nelt = t.nelt;
    nfr = t.nfr;
    naristas = t.naristas;
    tipo = t.tipo;

    map <int, cnodo2d *> nodos (t.nodos);
    map <int, celem2d *> eltos (t.eltos);
    map <int, carista *> aristas (t.aristas);
    vector <cfrontera2d *> fronteras (t.fronteras);
    map <std::pair <int,int>, carista *> nodart (t.nodart);

    // **************************************************************************************
    //cout << " [CMALLA01]    t.nodos.size() = " << t.nodos.size () << endl;
    //cout << " [CMALLA01]    z.nodos.size() = " << nodos.size () << endl;
    //for (int i=0; i<nsom; i++) {
    //    cout << i << " " << nodos[i]->id << " " << nodos[i]->x << " " << nodos[i]->y << endl;
    //}
    //cout << endl;
    // **************************************************************************************

//    this->id = t.id;
//    this->nsom = t.nsom;
//    this->nelt = t.nelt;
//    this->nfr = t.nfr;
//    this->naristas = t.naristas;
//    this->tipo = t.tipo;

//    for (int i=0; i<t.nsom; i++) {
//        this->nodos[i] = &(t.nodos[i]);             // Esto no me deja compilar, no sé por qué ...
//    }
//    nodos (t.nodos),
//    eltos (t.eltos),
//    aristas (t.aristas),
//    nodart (t.nodart),                 // Creo que no es necesario.
//    fronteras (t.fronteras) 
};
*/

/* -------------------------------------------------------------- */

/*
cmalla2d01::cmalla2d01 (cmalla2d01 *t) {

    // Constructor copia.

    int i;

    map <int, cnodo2d*> :: iterator inod;
    map <int, celem2d*> :: iterator ielt;
    map <int, carista*> :: iterator iart;

    // Copia de los parámetros escalares.

    // *****************************************************************************
    //cout << " (CMALLA01) Comenzamos a copiar" << endl;
    //cout << " (CMALLA01)         t->id = " << t->id << endl;
    //cout << " (CMALLA01)       t->nsom = " << t->nsom << endl;
    //cout << " (CMALLA01)       t->nelt = " << t->nelt << endl;
    //cout << " (CMALLA01)        t->nfr = " << t->nfr << endl;
    //cout << " (CMALLA01)   t->naristas = " << t->naristas << endl;
    //cout << " (CMALLA01)       t->tipo = " << t->tipo << endl;
    //inod = t->nodos.begin();
    //cout << " (CMALLA01)   t->nodos.begin() = " << inod->first << endl;
    //inod = t->nodos.end();
    //cout << " (CMALLA01)     t->nodos.end() = " << inod->first << endl;
    //cout << " (CMALLA01)     t->nodos.size() = " << t->nodos.size() << endl;
    // *****************************************************************************

    this->id = t->id;
    this->nsom = t->nsom;
    this->nelt = t->nelt;
    this->nfr = t->nfr;
    this->naristas = t->naristas;
    this->tipo = t->tipo;

    // *****************************************************************************
    //cout << " (CMALLA01) Hemos copiado los parámetros escalares" << endl;
    // *****************************************************************************

    // Copia de vectores y diccionarios.

    for (inod=t->nodos.begin(); inod!=t->nodos.end(); inod++) {
        this->nodos[inod->first] = inod->second;
    }
    for (ielt=t->eltos.begin(); ielt!=t->eltos.end(); ielt++) {
        this->eltos[ielt->first] = ielt->second;
    }
    for (iart=t->aristas.begin(); iart!=t->aristas.end(); iart++) {
        this->aristas[iart->first] = iart->second;
    }

    for (i=0; i<t->nfr; i++) {
        this->fronteras.push_back (t->fronteras[i]);
    }

    cnodo2d *newnod;
    for (i=0; i<t->nsom; i++) {
        newnod = new cnodo2d (t->nodos[i]->id, t->nodos[i]->x, t->nodos[i]->y);
        this->nodos[i] = newnod;
    }

    celem2d *newelt;
    for (i=0; i<t->nelt; i++) {
        newelt = new celem2d (t->eltos[i]->id, t->eltos[i]->nodos[0], t->eltos[i]->nodos[1], t->eltos[i]->nodos[2],
                                             t->eltos[i]->aristas[0], t->eltos[i]->aristas[1], t->eltos[i]->aristas[2]);
        this->eltos[i] = newelt;
    }

    carista *newart;
    for (i=0; i<t->naristas; i++) {
        newart = new carista (t->aristas[i]->id, t->aristas[i]->nodos[0], t->aristas[i]->nodos[1]);
        this->aristas[i] = newart;
    }

//    nodart (t.nodart),                 // Creo que no es necesario.
//    fronteras (t.fronteras) 

    // *****************************************************************************
    //cout << " (CMALLA01) Comprobamos el tablero NODOS:" << endl;
    //inod = this->nodos.begin();
    //cout << " (CMALLA01)   this->nodos.begin() = " << inod->first << endl;
    //inod = this->nodos.end();
    //cout << " (CMALLA01)     this->nodos.end() = " << inod->first << endl;
    //cout << " (CMALLA01)     this->nodos.size() = " << this->nodos.size() << endl;
    // *****************************************************************************

}
*/

/* -------------------------------------------------------------- */

cmalla2d01::~cmalla2d01 () {

//    delete [] id;
//    delete [] nsom;
//    delete [] nelt;
//    delete [] nfr;
//    delete [] naristas;
//    delete [] tipo;

    //    nodos->erase ();               //    delete [] nodos;
//    delete [] eltos;
//    delete [] aristas;
//    delete [] fronteras;

//    delete [] nodart;
}

/* -------------------------------------------------------------- */

void cmalla2d01::gnodart () {

    /* GNODART: Generación del diccionario NODART de la malla.
    */

    int i, n0, n1;
    carista *art;

    std::map <std::pair<int,int>, carista *> :: iterator j;     // Solo para pruebas (impresión de NODART).  Se podrá eliminar ...
    std::map <int, carista *> :: iterator k;      // Para recorrer el diccionario THIS->ARISTAS.

    // ************************************************************************************
    //cout << " (1+) this->aristas.size() = " << this->aristas.size() << endl;
    // ************************************************************************************

//    for (int i=0; i<this->naristas; i++) {
//        art = this->aristas [i];

    for (k=this->aristas.begin(); k!=this->aristas.end(); k++) {
//        i = k->first;
        art = k->second;
        i = art->id;
        n0 = art->nodos[0]->id;
        n1 = art->nodos[1]->id;

        // ************************************************************************************
        //cout << " i: " << i << "               n0: " << n0 << "  n1: " << n1 << endl;
        //cpar aux = cpar (n0, n1);
        //cout << "  aux = " << aux.key1 << "," << aux.key2 << endl;
        // ************************************************************************************

//        this->nodart.insert (std::pair <cpar, carista *> (cpar(n0, n1), art));
//        this->nodart.insert (std::pair <cpar, carista *> (aux, art));
        this->nodart.insert (std::make_pair (std::make_pair (n0,n1), art));
        this->nodart.insert (std::make_pair (std::make_pair (n1,n0), art));
//        this->nodart.insert (std::make_pair(n0,n1), art);
//        this->nodart.insert (std::make_pair(n1,n0), art);
    }

    // ************************************************************************************
//    this->pnodart ();
    //std::cout << "  NODART long = " << nodart.size () << std::endl;;
    //for (j=this->nodart.begin(); j!=this->nodart.end(); j++) {
    //    std::cout << "  NODART:            arista.id: " << j->second->id << std::endl;
    ////    std::cout << "  NODART:           j->first: " << j->first.key1 << "," << j->first.key2 << "     arista.id: " << j->second->id << std::endl;
    //}
    //cout << endl;
    // ************************************************************************************

    // ************************************************************************************
    //cout << " Hemos terminado el bucle en GNODART " << endl;
    // ************************************************************************************

}

/* -------------------------------------------------------------- */

void cmalla2d01::pnodart () {

    map <std::pair<int,int>, carista *> :: iterator j;     // Solo para pruebas (impresión de NODART).  Se podrá eliminar ...
    cout << "\n [PNODART]   long = " << nodart.size () << endl;
    for (j=this->nodart.begin(); j!=this->nodart.end(); j++) {
        cout << " [PNODART]     arista.id: " << (j->second)->id << "      nodos: " << (j->first).first << " " << (j->first).second << endl;
    }
    std::cout << std::endl;
}

/* -------------------------------------------------------------- */

void cmalla2d01::print () {

    // Impresión de los nodos: están en un diccionario, todos de forma consecutiva.

    if (this->nsom > 0) {
        printf ("\nNsom: %4d\n", this->nsom);
        printf ("Nodos:\n");
        for (int i=0; i<this->nsom; i++) {
           this->nodos[i]->print ();
        }
        printf ("\n");
    }

    // Impresión de los elementos:
    // los índices no son consecutivos; hay que recorrer las claves mediante un iterador.

    std::map <int, celem2d *>::iterator ielt;

    if (this->nelt > 0) {
        printf ("\nNelt: %4d\n", this->nelt);
        printf ("Elementos:\n");
        if (this->tipo == 3) {
//            for (int i=0; i<this->nelt; i++) {
//                this->eltos[i]->print03 ();
            for (ielt=this->eltos.begin(); ielt != this->eltos.end(); ielt++) {
//                cout << "   ******   Escribimos el elemento " << ielt->second->id << endl;
                ielt->second->print01 ();
            }
        }
        else {                           // Creo que nunca pasamos por aquí ...
            for (ielt=this->eltos.begin(); ielt != this->eltos.end(); ielt++) {
     //           ielt->second->print01 ();
                cout << " ielt->second->id = " << ielt->second->id << endl;
//            for (int i=0; i<this->nelt; i++) {
//                this->eltos[i]->print01 ();
            }
        }
        printf ("\n");
    }

    // Impresión de las aristas:
    // los índices no son consecutivos; hay que recorrer las claves mediante un iterador.

    std::map <int, carista *>::iterator iart;

    if (this->naristas > 0) {
        printf ("\nNaristas: %4d\n", this->naristas);
        printf ("Aristas:\n");
        for (iart=this->aristas.begin(); iart != this->aristas.end(); iart++) {
            iart->second->print ();
//        for (int i=0; i<this->naristas; i++) {
//            this->aristas[i]->print ();
        }
        printf ("\n");
    }

    // Impresión de los índices de nodos de las fronteras.

    printf ("\nFronteras:\n");
    for (int k=0; k<4; k++) {
        printf ("   %d:      ", k);
        for (int i=0; i<this->fronteras[k]->nodos.size(); i++) {
            printf ("%4d ", this->fronteras[k]->nodos[i]->id);
        }
        printf ("\n");
    }
    /*
    printf ("   0:      ");
    for (int i=0; i<this->fr0.nodos.size(); i++) {
        printf ("%4d ", this->fr0.nodos[i]->id);
    }
    printf ("\n");
    printf ("   1:      ");
    for (int i=0; i<this->fr1.nodos.size(); i++) {
        printf ("%4d ", this->fr1.nodos[i]->id);
    }
    printf ("\n");
    printf ("   2:      ");
    for (int i=0; i<this->fr2.nodos.size(); i++) {
        printf ("%4d ", this->fr2.nodos[i]->id);
    }
    printf ("\n");
    printf ("   3:      ");
    for (int i=0; i<this->fr3.nodos.size(); i++) {
        printf ("%4d ", this->fr3.nodos[i]->id);
    }
    */
    printf ("\n\n\n");
};

/* -------------------------------------------------------------- */

void cmalla2d01::fprint01 (int level) {

    /* FPRINT01: Escritura de la malla en el archivo SMALLA**.DAT.

       Entradas:
       - level: nivel actual.
    */

    char nomfic[12];
    int long1 = sprintf (nomfic, "smalla%02d.dat", level);
    cnodo2d *nod;
    celem2d *elt;
    carista *art;

    FILE *fic;
    fic = fopen (nomfic, "w");

    // Escritura de los números de nodos y de elementos.

    fprintf (fic, "%d %d %d %d\n", this->nsom, this->nelt, this->naristas, this->nfr);
//    fprintf (fic, "%d\n%d\n%d\n%d\n", this->nsom, this->nelt, this->naristas, this->nfr);

    // Escritura de los nodos.

    std::map <int, cnodo2d *> :: iterator kn;
    for (kn=this->nodos.begin(); kn!=this->nodos.end(); kn++) {
        nod = kn->second;
        fprintf (fic, "%d %.6f %.6f %.1f\n", nod->id, nod->x, nod->y, nod->w);
    }

    // Escritura de las aristas.

    std::map <int, carista *> :: iterator ka;
    for (ka=this->aristas.begin(); ka!=this->aristas.end(); ka++) {
        art = ka->second;
        fprintf (fic, "%d %d %d\n", art->id, art->nodos[0]->id, art->nodos[1]->id);
    }

    // Escritura de los elementos.

    std::map <int, celem2d *> :: iterator ke;
    for (ke=this->eltos.begin(); ke!=this->eltos.end(); ke++) {
        elt = ke->second;
        fprintf (fic, "%d %d %d %d %d %d %d\n", elt->id, elt->nodos[0]->id, elt->nodos[1]->id, elt->nodos[2]->id,
                                                elt->aristas[0]->id, elt->aristas[1]->id, elt->aristas[2]->id);
    }

    // Escritura de las fronteras.

    for (int k=0; k<4; k++) {
        fprintf (fic, "%d ", this->fronteras[k]->id);
        fprintf (fic, "%ld ", this->fronteras[k]->nodos.size());
        for (int i=0; i<this->fronteras[k]->nodos.size(); i++) {
            fprintf (fic, "%d ", this->fronteras[k]->nodos[i]->id);
        }
        fprintf (fic, "\n");
    }

    // Cierre del archivo.

    fclose (fic);
}

/* -------------------------------------------------------------- */

void cmalla2d01::fprint02 (int level) {

    /* FPRINT02: Escritura de la malla en el archivo SMALLA**.DAT.

       Entradas:
       - level: nivel actual.
    */

    char nomfic[12];
    int long1 = sprintf (nomfic, "smalla%02d.dat", level);
    cnodo2d *nod;
    celem2d *elt;

    // Apertura del archivo.

    std::ofstream fic;
    fic.open (nomfic, std::fstream::out);

    // Escritura de los números de nodos y de elementos.

    fic << this->nsom << " " << this->nelt << " " << this->nfr << "\n";

    // Escritura de los nodos.

    std::map <int, cnodo2d *> :: iterator j;
    for (j=this->nodos.begin(); j!=this->nodos.end(); j++) {
        nod = j->second;
        fic << nod->id << " ";
        fic << setprecision (8) << nod->x << " ";
        fic << setprecision (8) << nod->y << " ";
        fic << setprecision (2) << nod->w << "\n";
    }

    // Escritura de los elementos.

    std::map <int, celem2d *> :: iterator k;
    for (k=this->eltos.begin(); k!=this->eltos.end(); k++) {
        elt = k->second;
        fic << elt->id;
        for (int j=0; j<3; j++) {
            fic << " " << elt->nodos[j]->id;
        }
        for (int j=0; j<3; j++) {
            fic << " " << elt->aristas[j]->id;
        }
        fic << "\n";
    }

    // Escritura de las fronteras.

    for (int k=0; k<4; k++) {
        fic << this->fronteras[k]->id;                                // Identificador de cada frontera.
        fic << " " << this->fronteras[k]->nodos.size();               // Número de nodos de cada frontera.
        for (int i=0; i<this->fronteras[k]->nodos.size(); i++) {
            fic << " " << this->fronteras[k]->nodos[i]->id;
        }
        fic << "\n";
    }
                                                                    
    // Cierre del archivo.

    fic.close ();
}

/* -------------------------------------------------------------- */

void cmalla2d01::printv1 () {

    cnodo2d *nod;

    // Impresión de los vecinos de los nodos.

    printf ("\nVecinos de los nodos:\n");
    for (int i=0; i<this->nsom; i++) {
        nod = this->nodos[i];
        printf (" %4d:    ", nod->id);
        int nv = nod->v1nodos.size ();
        for (int j=0; j<nv; j++) {
            printf (" %4d", nod->v1nodos[j]->id);
        }
        printf ("\n");
    }
}

/* --------------------------------------------------------------------------- */

void cmalla2d01::read01 (const char *fileName, map <int, cnodo2d *> &gnodos, map <int, celem2d *> &geltos, map<int, carista *> &garistas) {

    cnodo2d *nod;
    celem2d *ef;
    carista *art;

    std::ifstream file;
    std::string line;

    int i, j, k, n1, n2, n3;
    double x, y, w;
    double *data = new double [10000];

    // Abrimos el fichero.

    // ****************************************************************************
    //cout << "\n [CMALLA01] Entramos en READ01\n" << endl;
    // ****************************************************************************

    file.open (fileName, std::fstream::in);

    // Mientras no se llegue a final de fichero, lee una fila del fichero y guarda los datos en un array.

    // ****************************************************************************
    //cout << "\n [CMALLA01] Leemos\n" << endl;
    // ****************************************************************************

    while (std::getline (file,line)) {

        // Si se ha producido algún error durante la lectura.

        if (std::ios_base::goodbit != 0) {
            std::cout << "Error al leer la linea\n";
            exit(-1);
        }

        // ***************************************************
        //cout << " [CMALLA01] Se guarda lo leído en un array " << endl;
        // ***************************************************

        // Se guarda lo leído en un array.

        data[i++] = ::atof (line.c_str ());

        // ***************************************************
        //cout << "        i = " << i << endl;
        // ***************************************************

    }

    file.close ();

    // Almacenamos los datos leídos.

    this->nsom = data [0];
    this->nelt = data [1];
    this->naristas = data [2];
    this->nfr = data [3];

    // ***************************************************
    //cout << " [READ01] Comenzamos a leer los nodos" << endl;
    // ***************************************************

    k = 4;
    for (i=0; i<this->nsom; i++) {         // Nodos.
        j = data [k];
        x = data [k+1];
        y = data [k+2];
        w = data [k+3];
        nod = new cnodo2d (j, x, y, w);
        gnodos [j] = nod;
        this->nodos [j] = nod;
        k += 4;

        // ***************************************************
        //cout << " [READ01]    Nodo: " << j << "       Coordenadas: (" << x << "," << y << ")" << endl;
        // ***************************************************
    }

    for (i=0; i<this->nelt; i++) {        // Elementos.
        j = data [k];
        n1 = data [k+1];
        n2 = data [k+2];
        n3 = data [k+3];
        ef = new celem2d (j, gnodos[n1], gnodos[n2], gnodos[n3]);
        geltos [j] = ef;
        this->eltos [j] = ef;
        k += 4;

        // ***************************************************
        //cout << " [READ01]    Elemento: " << j << "       Nodos: (" << n1 << "," << n2 << "," << n3 << ")" << endl;
        // ***************************************************
    }

    for (i=0; i<this->naristas; i++) {    // Aristas.
        j = data [k];
        n1 = data [k+1];
        n2 = data [k+2];
        art = new carista (j, gnodos[n1], gnodos[n2]);
        garistas [j] = art;
        this->aristas [j] = art;
        k += 3;

        // ***************************************************
        //cout << " [READ01]    Arista: " << j << "       Nodos: (" << n1 << "," << n2 << ")" << endl;
        // ***************************************************
    }

    /*
    for (i=0; i<this->nfr; i++) {    // Fronteras.
        j = data [k];
        n1 = data [k+1];
        n2 = data [k+2];
        art = new carista (j, gnodos[n1], gnodos[n2]);
        garistas [j] = art;
        this->aristas [j] = art;
        k += 3;
    }
    */

    // ****************************************************************************
    //cout << "\n [CMALLA01] Salimos de READ01\n" << endl;
    // ****************************************************************************

}

/* --------------------------------------------------------------------------- */

void cmalla2d01::read02 (const char *fileName, map <int, cnodo2d *> &gnodos, map <int, celem2d *> &geltos, map<int, carista *> &garistas) {

    cnodo2d *nod;
    celem2d *ef;
    carista *art;

    ifstream file;
    string line;

    int i, j, k, n1, n2, n3, n4, n5, n6, n7;
    double x, y, w;
    double *data = new double [10000];

    // Apertura del fichero.

    file.open (fileName, ios_base::in);

    // Primera línea: números de nodos, elementos, aristas y fronteras.

    getline (file, line);
    istringstream in (line);
    in >> n1 >> n2 >> n3 >> n4;
    this->nsom = n1;
    this->nelt = n2;
    this->naristas = n3;
    this->nfr = n4;

    // Lectura de los nodos.

    for (i=0; i<this->nsom; i++) {
        getline (file, line);
        istringstream in (line);
        in >> n1 >> x >> y >> w;

        nod = new cnodo2d (n1, x, y, w);
        gnodos [n1] = nod;
        this->nodos [n1] = nod;
    }

    // Lectura de los aristas.

    for (i=0; i<this->naristas; i++) {
        getline (file, line);
        istringstream in (line);
        in >> n1 >> n2 >> n3;

        art = new carista (n1, gnodos[n2], gnodos[n3]);
        garistas [n1] = art;
        this->aristas [n1] = art;
    }

    // Lectura de los elementos.

    for (i=0; i<this->nelt; i++) {
        getline (file, line);
        istringstream in (line);
//        in >> n1 >> n2 >> n3 >> n4;
        in >> n1 >> n2 >> n3 >> n4 >> n5 >> n6 >> n7;

//        ef = new celem2d (n1, gnodos[n2], gnodos[n3], gnodos[n4]);
        ef = new celem2d (n1, gnodos[n2], gnodos[n3], gnodos[n4], garistas[n5], garistas[n6], garistas[n7]);
        geltos [n1] = ef;
        this->eltos [n1] = ef;
    }

//    // Lectura de los aristas.
//
//    for (i=0; i<this->naristas; i++) {
//        getline (file, line);
//        istringstream in (line);
//        in >> n1 >> n2 >> n3;
//
//        art = new carista (n1, gnodos[n2], gnodos[n3]);
//        garistas [n1] = art;
//        this->aristas [n1] = art;
//    }

    // Lectura de los fronteras.

    for (i=0; i<4; i++) {
        file >> n1;
        file >> n2;
        vector <cnodo2d *> aux;
        for (j=0; j<n2; j++) {
            file >> n3;
            aux.push_back (gnodos[n3]);
        }
        this->fronteras.push_back (new cfrontera2d (n1, aux));
    }

    /*
    vector <vector <int> > all_integers;
    while (getline (std::cin, line)) {
        istringstream is (line);
        // *****************************************************
        cout << "    is: " << is << endl;
        // *****************************************************
        all_integers.push_back (vector <int> (istream_iterator <int> (is), istream_iterator <int> ()));
    }

//    for (i=0; i<this->nfr; i++) {
//        getline (file, line);
//        istringstream in (line);
//        in >> n1 >> n2 >> n3 >> n4;
//    }
    */

    // Cierre del fichero.

    file.close ();

}

/* --------------------------------------------------------------------------- */

