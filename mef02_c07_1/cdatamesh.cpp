#include "cdatamesh.h"

/* --------------------------------------------------------------------------- */
/* Clase CDATAMESH.                                                            */
/* --------------------------------------------------------------------------- */

cdatamesh::cdatamesh () {

    this->tipomalla = 0;
    this->nref = 0;
    this->nx = 0;
    this->ny = 0;
    this->vii = cnodo2d (0);
    this->vsd = cnodo2d (0);
};

/* --------------------------------------------------------------------------- */

void cdatamesh::read (const char *fileName) {

//    data = [];

    std::ifstream file;
    std::string line;

    int i = 0;
//    cdatamesh cdata = cdatamesh ();
//    double *data = new double [10];
    double *data = new double [15];
    char *data2 = new char [10];

    // Abrimos el fichero.

    file.open (fileName, std::fstream::in);

    if (!file.is_open()) {
        std::cout << "\n    *** ERROR en la apertura del archivo " << fileName << " *** \n" << endl;
        exit(-1);
    }

    // Mientras no se llegue a final de fichero lee una fila del fichero y guarda los datos en un array.

    while (std::getline(file,line)) {

        // Si se ha producido algun error durante la lectura.

        if (std::ios_base::goodbit != 0) {
            std::cout << "  ***  Error al leer la línea  ***  \n";
            exit (-1);
        }

        // Se ignoran los comentarios.

        if (line[0] == '#')
            continue;

        // Se guarda lo leído en un array.

//        data2[i++] = line.c_str ();
        data[i++] = ::atof (line.c_str ());
    }

    file.close ();

    // Almacenamiento de los datos en una instancia.

    this->tipomalla = data [0];
//    this->nomfic = data [1];
    this->nref = data [2];
    this->tref0 = data [3];
    this->tref1 = data [4];
    this->sigma = data [5];
    this->nx = data [6];
    this->ny = data [7];
    this->vii = cnodo2d (0, data[8], data[9]);
    this->vsd = cnodo2d (0, data[10], data[11]);

    // ***********************************************************************
    //cout << " [CDATAMESH]      data[8] = " << data[8] << endl;
    // ***********************************************************************

//    this->tipomalla = ::atoi (data [0]);
//    this->nomfic = data [1];
//    this->nref = ::atoi (data [2]);
//    this->nx = ::atoi (data [3]);
//    this->ny = ::atoi (data [4]);
//    this->vii = cnodo2d (0, ::atof (data[5]), ::atof (data[6]));
//    this->vsd = cnodo2d (0, ::atof (data[7]), ::atof (data[8]));

//    this->vii->x = data [3];
//    this->vii->y = data [4];
//    this->vsd->x = data [5];
//    this->vsd->y = data [6];

    delete[] data;
}

/* --------------------------------------------------------------------------- */

void cdatamesh::print () {

    // Impresión de los datos de la malla.

    map <int, const char *> d1;
    d1[0] = "Leída desde archivo";
    d1[1] = "Q2T";
    d1[2] = "Q4T";
    d1[3] = "Generada por refinamientos sucesivos";

    cout << "\nDatos de la malla:\n" << endl;
    printf ("                              Tipo de malla:  %s (%d)\n", d1[this->tipomalla], this->tipomalla);
//    printf ("                              Tipo de malla:  %s\n", d1[this->tipomalla]);
//    printf ("                              Tipo de malla: %d (%s)\n", this->tipomalla, s1[this->tipomalla]);

    if (this->tipomalla < 3) {
        printf ("    Número de nodos en abscisas y ordenadas:  %d, %d\n", this->nx, this->ny);
    } else {
        printf ("                          Número de niveles:  \n");
    }

    printf ("                 Vértice inferior izquierdo:  (%.5f, %.5f)\n", this->vii.x, this->vii.y);
    printf ("                   Vértice superior derecho:  (%.5f, %.5f)\n", this->vsd.x, this->vsd.y);
    cout << "\n                   ______________________________________\n" << endl;
};

/* -------------------------------------------------------------- */

