#include <iostream>
using std::cout;
using std::endl;

#ifndef cmark_h_
    #include "cmark.h"
#endif

/* ----------------------------------------------------------------------- */

#ifndef cmark01_h_
#define cmark01_h_

class cmark01 : public cmark {

    public:

        cmark01 ();
        void operator () (cmalla2d01 *);
};

#endif

/* ----------------------------------------------------------------------- */
