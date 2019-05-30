#include <iostream>
using std::cout;
using std::endl;

#include <algorithm>
using std::max;

#ifndef cmark_h_
    #include "cmark.h"
#endif

/* ----------------------------------------------------------------------- */

#ifndef cmark03_h_
#define cmark03_h_

class cmark03 : public cmark {

    public:

        cmark03 ();
        void operator () (cmalla2d01 *);
};

#endif

/* ----------------------------------------------------------------------- */
