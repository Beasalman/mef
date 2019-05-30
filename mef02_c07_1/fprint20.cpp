#include "fprint20.h"

/* ------------------------------------------------------------------------------------ */

void fprint20 (int level, VectorXd u) {

    /* FPRINT20: Escritura del obstáculo.

    Entradas:
    - level: nivel actual.
    - u:     vector.
    */

    char nomfic[12];
    int long1 = sprintf (nomfic, "sobstac%02d.dat", level);

    // Apertura del archivo.

    std::ofstream fic;
    fic.open (nomfic, std::fstream::out);

    // Escritura de los índices de los nodos y valores del vector.

    int n = u.size ();
    for (int i=0; i<n; i++) {
        fic << i << " ";
        fic << setprecision (8) << u(i) << "\n";
    }

    // Cierre del archivo.

    fic.close ();
}

/* ------------------------------------------------------------------------------------ */

