#include <stdio.h>
#ifndef ELLENFEL_INIT_H
#define ELLENFEL_INIT_H
    typedef struct Ellenfel{int elet;int pont;}Ellenfel;
    struct Ellenfel *ellenfel_init(int korszam, Ellenfel *ellenfelek);
#endif