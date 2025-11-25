#include <stdio.h>
#ifndef ELLENFEL_INIT_H
#define ELLENFEL_INIT_H
    struct Ellenfel *ellenfel_init(int korszam, Ellenfel *ellenfelek);
    typedef struct Ellenfel{int elet;int pont;}Ellenfel;
#endif