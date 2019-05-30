#include <iostream>
using std::cout;
using std::endl;

#ifndef cmalla2d01_h_
    #include "cmalla2d01.h"
#endif

/* ----------------------------------------------------------------------- */

#ifndef cmark_h_
#define cmark_h_

class cmark {

    public:

        double sigma;

        cmark ();
        virtual void operator () (cmalla2d01 *);
        virtual void operator () (cmalla2d01 *, VectorXd, VectorXd);
};

#endif

/* ----------------------------------------------------------------------- */
