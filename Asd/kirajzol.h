#include <stdio.h>
#include "ellenfel_init.h"
#ifndef KIRAJZOL_H
#define KIRAJZOL_H
    typedef struct Torony{
        int hatotav;
        int sebzes;
        int ar;
        int max_celpontok;
        char icon;
    }Torony;
    void kirajzol(int eletek, int pontszam, int elkoltheto_pontok, Torony *tornyok, Ellenfel *ellenfelek, int kori, int kor_lepes, int legyozott_ellenfelek);
#endif