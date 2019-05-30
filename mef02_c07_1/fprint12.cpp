#include "fprint12.h"

/* ------------------------------------------------------------------------------------ */

void fprint12 (int level, cmalla2d01 *m, canalitica2d *analyt) {

    /* FPRINT12: Escritura de la solución analítica en un archivo.
                 Función de dos variables espaciales.

    Entradas:
    - level: nivel actual.
    - u:     vector.
    */

    double x, y;
    char nomfic[13];
    int long1 = sprintf (nomfic, "sanalit%02d.dat", level);

    // Apertura del archivo.

    std::ofstream fic;
    fic.open (nomfic, std::fstream::out);

    // Escritura de los índices de los nodos y valores de la solución.

    for (int i=0; i<m->nsom; i++) {
        x = m->nodos[i]->x;
        y = m->nodos[i]->y;
        fic << i << " ";
        fic << setprecision (8) << (*analyt)(x,y) << "\n";
    }

    // Cierre del archivo.

    fic.close ();
}

/* ------------------------------------------------------------------------------------ */

void fprint12 (int level, int itp, cmalla2d01 *m, canalitica2d *analyt) {

    /* FPRINT12: Escritura de la solución analítica en un archivo.
                 Función de dos variables espaciales.

    Entradas:
    - level: nivel actual.
    - u:     vector.
    */

    double x, y;
    char nomfic[13];
//    int long1 = sprintf (nomfic, "sanalit%02d.dat", level);
    int long1 = sprintf (nomfic, "sanalit%02dt%03d.dat", level, itp);

    // Apertura del archivo.

    std::ofstream fic;
    fic.open (nomfic, std::fstream::out);

    // Escritura de los índices de los nodos y valores de la solución.

    for (int i=0; i<m->nsom; i++) {
        x = m->nodos[i]->x;
        y = m->nodos[i]->y;
        fic << i << " ";
        fic << setprecision (8) << (*analyt)(x,y) << "\n";
    }

    // Cierre del archivo.

    fic.close ();
}

/* ------------------------------------------------------------------------------------ */

void fprint12 (int level, cmalla2d01 *m, double (*f)(double,double)) {

    /* FPRINT12: Escritura de la solución analítica en un archivo.
                 Función de dos variables espaciales.

    Entradas:
    - level: nivel actual.
    - u:     vector.
    */

    double x, y;
    char nomfic[13];
    int long1 = sprintf (nomfic, "sanalit%02d.dat", level);

    // Apertura del archivo.

    std::ofstream fic;
    fic.open (nomfic, std::fstream::out);

    // Escritura de los índices de los nodos y valores de la solución.

    for (int i=0; i<m->nsom; i++) {
        x = m->nodos[i]->x;
        y = m->nodos[i]->y;
        fic << i << " ";
        fic << setprecision (8) << f(x,y) << "\n";
    }

    // Cierre del archivo.

    fic.close ();
}

/* ------------------------------------------------------------------------------------ */

void fprint12 (int level, cmalla2d01 *m, double t, double (*f)(double,double,double)) {

    /* FPRINT12: Escritura de la solución analítica en un archivo.
                 Función de dos variables espaciales y del tiempo.

    Entradas:
    - level: nivel actual.
    - u:     vector.
    */

    double x, y;
    char nomfic[13];
    int long1 = sprintf (nomfic, "sanalit%02d.dat", level);

    // Apertura del archivo.

    std::ofstream fic;
    fic.open (nomfic, std::fstream::out);

    // Escritura de los índices de los nodos y valores de la solución.

    for (int i=0; i<m->nsom; i++) {
        x = m->nodos[i]->x;
        y = m->nodos[i]->y;
        fic << i << " ";
        fic << setprecision (8) << f(x,y,t) << "\n";
    }

    // Cierre del archivo.

    fic.close ();
}

/* ------------------------------------------------------------------------------------ */

void fprint12 (int level, cmalla2d01 *m, double (*f)(double,double), VectorXd &ua) {

    /* FPRINT12: Escritura de la solución analítica en un archivo.
                 Función de dos variables espaciales.
                 Discretización de la solución analítica en un vector.

    Entradas:
    - level: nivel actual.
    - u:     vector.
    */

    double x, y, z;
    char nomfic[13];
    int long1 = sprintf (nomfic, "sanalit%02d.dat", level);

    // Apertura del archivo.

    std::ofstream fic;
    fic.open (nomfic, std::fstream::out);

    // Escritura de los índices de los nodos y valores de la solución.

    for (int i=0; i<m->nsom; i++) {
        x = m->nodos[i]->x;
        y = m->nodos[i]->y;
        z = f(x,y);
        fic << i << " ";
        fic << setprecision (8) << z << "\n";
        ua (i) = z;
    }

    // Cierre del archivo.

    fic.close ();
}

/* ------------------------------------------------------------------------------------ */

void fprint12 (int level, int itp, cmalla2d01 *m, double (*f)(double,double), VectorXd &ua) {

    /* FPRINT12: Escritura de la solución analítica en un archivo.
                 Función de dos variables espaciales.
                 Discretización de la solución analítica en un vector.

    Entradas:
    - level: nivel actual.
    - u:     vector.
    */

    double x, y, z;
    char nomfic[13];
    int long1 = sprintf (nomfic, "sanalit%02dt%03d.dat", level, itp);

    // Apertura del archivo.

    std::ofstream fic;
    fic.open (nomfic, std::fstream::out);

    // Escritura de los índices de los nodos y valores de la solución.

    for (int i=0; i<m->nsom; i++) {
        x = m->nodos[i]->x;
        y = m->nodos[i]->y;
        z = f(x,y);
        fic << i << " ";
        fic << setprecision (8) << z << "\n";
        ua (i) = z;
    }

    // Cierre del archivo.

    fic.close ();
}

/* ------------------------------------------------------------------------------------ */

void fprint12 (int level, cmalla2d01 *m, double t, double (*f)(double,double,double), VectorXd &ua) {

    /* FPRINT12: Escritura de la solución analítica en un archivo.
                 Función de dos variables espaciales y del tiempo.
                 Discretización de la solución analítica en un vector.

    Entradas:
    - level: nivel actual.
    - u:     vector.
    */

    double x, y, z;
    char nomfic[13];
    int long1 = sprintf (nomfic, "sanalit%02d.dat", level);

    // Apertura del archivo.

    std::ofstream fic;
    fic.open (nomfic, std::fstream::out);

    // Escritura de los índices de los nodos y valores de la solución.

    for (int i=0; i<m->nsom; i++) {
        x = m->nodos[i]->x;
        y = m->nodos[i]->y;
        z = f (x,y,t);
        fic << i << " ";
        fic << setprecision (8) << z << "\n";
        ua (i) = z;
    }

    // Cierre del archivo.

    fic.close ();
}

/* ------------------------------------------------------------------------------------ */

