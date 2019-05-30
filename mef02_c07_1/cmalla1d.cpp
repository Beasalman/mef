#include "cmalla1d.h" 

/* ------------------------------------------------------------------------------------------------- */

cmalla1d::cmalla1d () {

    this->id = -1000;
    this->nsom = 0;
    this->nelt = 0;
    this->nfr = 2;
	
	this->arroba = 1.e+15;
}

/* ------------------------------------------------------------------------------------------------- */

cmalla1d::cmalla1d (int i, int ns, int ne) {

    this->id = i;
    this->nsom = ns;
    this->nelt = ne;
    this->nfr = 2;
	
	this->arroba = 1.e+15;
}

/* ------------------------------------------------------------------------------------------------- */

cmalla1d::cmalla1d (int i, int ns, int ne, vector <double> xnods) {

    this->id = i;
    this->nsom = ns;
    this->nelt = ne;
    this->nfr = 2;
	
    this->arroba = 1.e+15;
    
    for (int j=0; j<ns; j++) {
        this->nodos.push_back (new cnodo1d (j, xnods[j]));
    }
}

/* ------------------------------------------------------------------------------------------------- */

cmalla1d::cmalla1d (int i, int ns, int ne, vector <cnodo1d *> nods) {

    this->id = i;
    this->nsom = ns;
    this->nelt = ne;
    this->nfr = 2;
	
    this->arroba = 1.e+15;
    
    for (int j=0; j<ns; j++) {
        this->nodos.push_back (nods[j]);  
    }
}

/* ------------------------------------------------------------------------------------------------- */

cmalla1d::cmalla1d (int i, int ns, int ne, std::vector<cnodo1d *> nods, std::vector<celem1d *> elts) {

    this->id = i;
    this->nsom = ns;
    this->nelt = ne;
    this->nfr = 2;
	
	this->arroba = 1.e+15;

    for (int j=0; j< this->nsom; j++)
        this->nodos.push_back (nods[j]);

    for (int j=0; j< this->nelt; j++)
        this->eltos.push_back (elts[j]);      
}

/* ------------------------------------------------------------------------------------------------- */

cmalla1d::cmalla1d (const cmalla1d &t) :

    // Constructor copia.
    
	id (t.id),
	nsom (t.nsom),
	nelt (t.nelt),
	nfr (t.nfr),
	arroba (t.arroba),
	nodos (t.nodos),
	eltos (t.eltos),
	fronteras (t.fronteras)
	{}
	
/* ------------------------------------------------------------------------------------------------- */

void cmalla1d::save (std::vector<double> u) {

    // Paso de la solución a los nodos.
    
    cnodo1d *nod;
    
    for (int i=0; i<this->nsom; i++){
        nod = this->nodos[i];
        nod->uh = u[i];
    }
}

/* ------------------------------------------------------------------------------------------------- */

void cmalla1d::save (VectorXd u) {

    // Paso de la solución a los nodos.
    
    cnodo1d *nod;
    
    for (int i=0; i<this->nsom; i++){
        nod = this->nodos[i];
        nod->uh = u(i);
    }
}

/* ------------------------------------------------------------------------------------------------- */

celem1d * cmalla1d::locp (double y, cvelocity1d *velo, celem1d *elto) {

    /* LOCP: Localiza el elemento de la malla al que pertenece un punto.

    Entradas:
    - y:    coordenada del punto a localizar.
    - elto: elemento en el que comenzamos la búsqueda.
    */

    celem1d *ef;
    double xmin = this->nodos[0]->x;
    double xmax = this->nodos[this->nsom-1]->x;
    int ne1 = this->nelt - 1;

    // ********************************************************
    //double vel = -1.05;
//    cout << endl;
//    cout << endl;
//    if (y <= xmin) {
//        cout << "          ****** SALIMOS POR LA IZQUIERDA ****** " << endl;
//    } else if (y >= xmax) {
//        cout << "          ****** SALIMOS POR LA DERECHA ****** " << endl;
//    } else if (velo(y) >= 0.0) {
//        cout << "          ****** VELOCIDAD POSITIVA ****** " << endl;
//    } else if (velo(y) < 0.0) {
//        cout << "          ****** VELOCIDAD NEGATIVA ****** " << endl;
//    } else {
//        cout << "          ****** *************************** ****** " << endl;
//    }
//    cout << " [CMALLA1d.LOCP]      y = " << y << "        velo = " << velo (y);
//    cout << " [CMALLA1d.LOCP]      xmin = " << xmin << "        xmax = " << xmax << "    y = " << y << endl;
    // ********************************************************

    if (y <= xmin) {
        // ********************************************************
        //cout << " [1]   ef = " << eltos[0]->id << endl;
        // ********************************************************
        return this->eltos[0];

    } else if (y >= xmax) {
        // ********************************************************
        //cout << " [2]   ef = " << eltos[this->nelt-1]->id << endl;
        // ********************************************************
        return this->eltos[this->nelt-1];

//    } else if (vel >= 0.0) {
    } else if ((*velo)(y) >= 0.0) {
//        int i = elto->id + 1;
//        int i = elto->id;
        int i = min (elto->id + 1, ne1);
//        ef = this->eltos[i];
        // ********************************************************
        //cout << " [3-]     Comenzamos en el elemento " << i << endl;
        // ********************************************************
//        if (ef->contains (y)) {
//            // ********************************************************
//            cout << " [3]   ef = " << ef->id << "     Nos vamos" << endl;
//            // ********************************************************
//            return ef;
//        }
        while (i >= 0) { 
            ef = this->eltos[i];
            // ********************************************************
            //cout << " [3-]     Buscamos en el elemento " << ef->id << endl;
            // ********************************************************
            if (ef->contains (y)) {
                // ********************************************************
                //cout << " [3]   ef = " << ef->id << "     Nos vamos ***************************" << endl;
                // ********************************************************
                return ef;
            }
            i--;
        }

//    } else if (vel < 0.0) {
    } else if ((*velo)(y) < 0.0) {
//        int i = elto->id + 1;
//        int i = elto->id;
        int i = max (elto->id - 1, 0);
//        ef = this->eltos[i];
        // ********************************************************
        //cout << " [4-]     Comenzamos en el elemento " << i << endl;
        // ********************************************************
//        if (ef->contains (y)) {
//            // ********************************************************
//            //cout << " [3]   ef = " << ef->id << "     Nos vamos " << endl;
//            // ********************************************************
//        }
        while (i <= this->nelt-1) {
            ef = this->eltos[i];
            // ********************************************************
            //cout << " [4-]     Buscamos en el elemento " << ef->id << endl;
            // ********************************************************
            if (ef->contains (y)) {
                // ********************************************************
                //cout << " [4]   ef = " << ef->id << "    Nos vamos " << endl;
                // ********************************************************
                return ef;
            }
            i++;
        }
    }
}

/* ------------------------------------------------------------------------------------------------- */

void cmalla1d::print () {

    // Impresión de los nodos.

    if (this->nsom > 0) {
        printf ("\nNsom: %4d\n", this->nsom);
        printf ("Nodos:\n");
        for (int i=0; i<this->nsom; i++) {
            this->nodos[i]->print ();
        }
        printf ("\n");
    }

    // Impresión de los elementos.

    if (this->nelt > 0) {
        printf ("\nNelt: %4d\n", this->nelt);
        printf ("Elementos:\n");
	
        for (int i=0; i<this->nelt; i++) {
    	    this->eltos[i]->print ();
    	}
        printf ("\n");
    }

    // Impresión de los índices de nodos de las fronteras.

    printf ("\nFronteras:\n");
    for (int k=0; k<this->nfr; k++) {
        this->fronteras[k]->print ();   
    }
}

/* ------------------------------------------------------------------------------------------------- */

void cmalla1d::fprint01 (int level) {
    
    /* FPRINT01: Escritura de las coordenadas de los nodos en el archivo SMALLA**.DAT.

    Entradas:
    - level: nivel actual.
    */

    char nomfic[12];
    int long1 = sprintf (nomfic, "smalla%02d.dat", level);

    FILE *fic;
    fic = fopen (nomfic, "w");

    // Escritura de los nodos.

    for (int i=0; i<this->nsom; i++) {
        fprintf (fic, "%d %.6f\n", this->nodos[i]->id, this->nodos[i]->x);
    }

    // Cierre del archivo.

    fclose (fic);    
}

/* ------------------------------------------------------------------------------------------------- */

void cmalla1d::fprint02 (int level) {
    
    /* FPRINT02: Escritura de la malla completa en el archivo SMALLA**.DAT.

    Entradas:
    - level: nivel actual.
    */

    char nomfic[12];
    int long1 = sprintf (nomfic, "smalla%02d.dat", level);

    FILE *fic;
    fic = fopen (nomfic, "w");

    // Escritura de los números de nodos y de elementos.

    fprintf (fic, "%d %d %d\n", this->nsom, this->nelt, this->nfr);

    // Escritura de los nodos.

    for (int i=0; i<this->nsom; i++) {
        fprintf (fic, "%d %.6f\n", this->nodos[i]->id, this->nodos[i]->x);
    }

    // Escritura de los elementos.

    for (int i=0; i<this->nelt; i++) {
        fprintf (fic, "%d %d %d\n", this->eltos[i]->id, this->eltos[i]->nodos[0]->id, this->eltos[i]->nodos[1]->id);
    }

    // Escritura de las fronteras.

    for (int k=0; k<this->nfr; k++) {
        fprintf (fic, "%d   %d\n", this->fronteras[k]->id, this->fronteras[k]->nodo->id);
    }

    // Cierre del archivo.

    fclose (fic);    
}

/* ------------------------------------------------------------------------------------------------- */

void cmalla1d::fprint03 (int level) {
    
    /* FPRINT03: Escritura de la malla "S" en el archivo SSMALLA**.DAT.

    Entradas:
    - level: nivel actual.
    */

    char nomfic[14];
    int long1 = sprintf (nomfic, "ssmalla%03d.dat", level);

    FILE *fic;
    fic = fopen (nomfic, "w");

    // Escritura de los nodos.

    for (int i=0; i<this->nsom; i++) {
        fprintf (fic, "%d %.8f\n", this->nodos[i]->id, this->nodos[i]->s);
    }

    // Cierre del archivo.

    fclose (fic);    
}

/* ------------------------------------------------------------------------------------------------- */

void cmalla1d::fprint04 (int level) {
    
    /* FPRINT04: Escritura del valor del activo en el archivo SVALUE**.DAT.

    Entradas:
    - level: nivel actual.
    */

    char nomfic[14];
    int long1 = sprintf (nomfic, "svaluet%04d.dat", level);

    FILE *fic;
    fic = fopen (nomfic, "w");

    // Escritura de los nodos.

    for (int i=0; i<this->nsom; i++) {
        fprintf (fic, "%d %.8f\n", this->nodos[i]->id, this->nodos[i]->vh);
    }

    // Cierre del archivo.

    fclose (fic);    
}

/* ------------------------------------------------------------------------------------------------- */

void cmalla1d::fprint05 (int level) {
    
    /* FPRINT04: Escritura de la expresión analítica del valor del activo en el archivo SBS**.DAT.

    Entradas:
    - level: nivel actual.
    */

    char nomfic[14];
    int long1 = sprintf (nomfic, "sbs%04d.dat", level);

    FILE *fic;
    fic = fopen (nomfic, "w");

    // Escritura.

    for (int i=0; i<this->nsom; i++) {
        fprintf (fic, "%d %.8f\n", this->nodos[i]->id, this->nodos[i]->va);
    }

    // Cierre del archivo.

    fclose (fic);    
}

/* ------------------------------------------------------------------------------------------------- */

