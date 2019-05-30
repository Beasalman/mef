#include "bicgstab01.h"

/* ----------------------------------------------------------------------------------------------------- */

void bicgstab01 (SparseMatrix <double> a, VectorXd b, VectorXd &x, int niter, double eps, int &iter, int &conv) {

    /* BICGSTAB01: Método de doble gradiente conjugado.

    Entradas:
    - a:     matriz del sistema.
    - b:     vector segundo miembro.
    - niter: número máximo de iteraciones.
    - eps:   error relativo máximo.

    Entrada/salidas:
    - x:    solución del sistema de ecuaciones.
    - iter: iteraciones realizadas.
    - conv: indicador de convergencia.
    */

    int k;
    int n = b.size ();
    double alpha, beta, omega, r2, s2, emax;
    VectorXd p (n), r (n), q (n), s (n), ap (n), as (n);

    /* ------------------------------------------------------------------------------------------------- */
    // Inicialización.

    r = b - a * x;                       // Residuo.
    p = util02 (r);                      // Dirección de descenso.
    q = util02 (r);                      // Vector auxiliar, constante.
    r2 = r.dot (q);
    emax = eps * eps * r2;

    // Bucle iterativo.
  	
    for (k=0; k<niter; k++) {
        ap = a * p;
        alpha = r2 / q.dot (ap);
        s = r - alpha * ap;

        as = a * s;
        omega = as.dot (s) / as.dot (as);
        x = s + alpha * p;                      // Es lo que tengo en mis notas, pero creo que está mal ...
//        x = x - alpha * p;                      // A comprobar!
        x = x + omega * s;
        r = s - omega * as;

        s2 = r.dot (q);
//        cout << "   BiGC iter: " << k << "        s2: " << s2 << endl;
//        if (s2 < emax) {
        if (r.dot (r) < emax) {
            conv = 1;
            iter = k + 1;
            break;
        }

        beta = (s2 / r2) * (alpha / omega);
        p = p - omega * ap;
        p = r + beta * p;
        r2 = s2;
    }

    return;
}

/* ----------------------------------------------------------------------------------------------------- */

