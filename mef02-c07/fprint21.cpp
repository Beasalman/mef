#include "fprint21.h"

/* ------------------------------------------------------------------------------------ */

void fprint21 (int level, VectorXd u) {

    /* FPRINT19: Escritura de la aproximación numérica en un archivo.

    Entradas:
    - level: nivel actual.
    - u:     vector.
    */

    char nomfic[12];
    int long1 = sprintf (nomfic, "sunumap%02d.dat", level);

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

void fprint21 (int level, int itp, VectorXd u) {

    /* FPRINT19: Escritura de la aproximación numérica en un archivo.

    Entradas:
    - level: nivel actual.
    - u:     vector.
    */

    char nomfic[12];
    int long1 = sprintf (nomfic, "sunumap%02dt%03d.dat", level, itp);

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

