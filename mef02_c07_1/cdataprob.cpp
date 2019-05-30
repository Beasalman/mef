#include "cdataprob.h"

/* --------------------------------------------------------------------------- */
/* Clase CDATAPROB.                                                            */
/* --------------------------------------------------------------------------- */

cdataprob::cdataprob () {

    this->dominio = -1;
    this->second = -1;
    this->analitica = -1;
};

/* --------------------------------------------------------------------------- */

void cdataprob::read (const char *fileName) {

    std::ifstream file;
    std::string line;

    int i = 0;
    double *data = new double [29];

    // Abrimos el fichero.


    file.open (fileName, std::fstream::in);


    if (!file.is_open()) {
        std::cout << "\n    *** ERROR en la apertura del archivo " << "fileName" << " *** \n" << endl;
        exit(-1);
    }

    // Mientras no se llegue a final de fichero, lee una fila del fichero y guarda los datos en un array.

    while (std::getline(file,line)) {

        // Si se ha producido algún error durante la lectura.

        if (std::ios_base::goodbit != 0) {
            std::cout << "Error al leer la línea\n";
            exit(-1);
        }

        // Se ignoran los comentarios.

        if (line[0] == '#')
            continue;

        // Se guarda lo leído en un array.

        data[i++] = ::atof (line.c_str ());
    }

    file.close ();

    // Almacenamiento de los datos en una instancia.

    int j = 0;
    this->dominio = data [j];        j+= 1;
    this->second = data [j];         j+= 1;
    this->analitica = data [j];      j+= 1;
    this->tipodiff = data [j];       j+= 1;
    this->tini = data [j];           j+= 1;
    this->tfin = data [j];           j+= 1;
    this->product = data[j];         j+= 1;
    this->option = data[j];          j+= 1;
    this->mtmarket = data[j];        j+= 1;
    this->sigma = data [j];          j+= 1;
    this->rho = data [j];            j+= 1;
    this->RB = data [j];             j+= 1;
    this->RC = data [j];             j+= 1;
    this->r = data [j];              j+= 1;
    this->rr = data [j];             j+= 1;
    this->theta0 = data [j];          j+= 1;
    this->kappa = data [j];          j+= 1;
    this->nuinf = data [j];          j+= 1;
    this->lambdaB = data [j];        j+= 1;
    this->lambdaC = data [j];        j+= 1;
    this->sF = data [j];             j+= 1;
    this->strike = data[j];          j+= 1;
    this->sinf = data[j];            j+= 1;

    delete[] data;
}

/* --------------------------------------------------------------------------- */

void cdataprob::print () {

    // Impresión de los datos relativos a los métodos numéricos.

    cout << "\n__________________________________________________________________________________\n" << endl;
    cout << endl;
    if (this->product == 1) {
        cout << "     Opción europea,";
    } else if (this->product == 2) {
        cout << "     Opción americana,";
    }

    if (this->option == 1) {
        cout << "     tipo call" << endl;
    } else if (this->product == 2) {
        cout << "     tipo put" << endl;
    }

    cout << "\n    Sigma = " << this->sigma;
    cout << "         Rho = " << this->rho << endl;
    cout << "         RB = " << this->RB;
    cout << "         RC = " << this->RC;
    cout << "           r = " << this->r;
    cout << "         r_R = " << this->rr;
    cout << "         theta = " << this->theta0;
    cout << "       kappa = " << this->kappa;
    cout << "       lambdaC = " << this->lambdaC;
    cout << "       sF = " << this->sF;
    cout << "         lambdaB = " << this->lambdaB << endl;
    cout << "      Sinf = " << this->sinf;
    cout << "         nuinf = " << this->nuinf << endl;
    cout << "    Strike = " << this->strike << endl;

    cout << "\n__________________________________________________________________________________\n" << endl;
};

/* -------------------------------------------------------------- */

