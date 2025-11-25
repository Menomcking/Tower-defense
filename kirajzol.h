#include <stdio.h>
#ifndef KIRAJZOL_H
#define KIRAJZOL_H
    void kirajzol(int eletek, int pontszam, int elkoltheto_pontok, Torony *tornyok, Ellenfel *ellenfelek, int kori);

    typedef struct Ellenfel{
        int elet;
        int pont;
    }Ellenfel;
    typedef struct Torony{
        int hatotav;
        int sebzes;
        int ar;
        int max_celpontok;
        char icon[7];
    }Torony;
#endif