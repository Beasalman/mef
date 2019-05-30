#include "fprint13.h"

/* ------------------------------------------------------------------------------------ */

void fprint13 (SparseMatrix <double> a, VectorXd b) {

    /* FPRINT13: 

    Entradas:
    */

    int n = b.size ();

    // Apertura del archivo.

    std::ofstream fic;
    fic.open ("matriz-y-vector.py", std::fstream::out);

    fic << "import numpy as np" << "\n\n";
    fic << "n = " << n << "\n";
    fic << "a = np.zeros ((n,n), 'f')" << "\n";
    fic << "b = np.zeros (n, 'f')" << "\n\n";

    // Matriz.

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (abs (a.coeffRef (i,j)) > 1.e-12) {
                fic << "a [" << i << "," << j << "] = ";
                fic << setprecision (8) << a.coeffRef (i,j) << "\n";
            }
        }
    }

    // Segundo miembro.

    for (int i=0; i<n; i++) {
        fic << "b [" << i << "] = ";
        fic << setprecision (8) << b (i) << "\n";
    }

    // Cierre del archivo.

    fic.close ();
}

/* ------------------------------------------------------------------------------------ */

