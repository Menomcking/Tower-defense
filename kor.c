#include <stdio.h>
#include <stdbool.h>
#include "kirajzol.h"
#include "kor_vege.h"

//Itt fut a játék fő része, addig ismételgeti a kirazjolást amíg vége nincs a körnek.
void kor(int eletek, int pontszam, int elkoltheto_pontok, Torony *tornyok, Ellenfel *ellenfelek, int kori, int kor_lepes, int legyozott_ellenfelek, char *nev){
    ellenfelek = ellenfel_init(kori, ellenfelek);
    const int osszes_ellenfel = 5;
    kor_lepes = 0;
    while((eletek) > 0 && legyozott_ellenfelek < osszes_ellenfel){
        for(int i = 0; i < 5; i++){
            printf("%d", ellenfelek[i].elet);
        }
        kimenet ki = kirajzol(eletek, pontszam, elkoltheto_pontok, tornyok, ellenfelek, kori, kor_lepes, legyozott_ellenfelek);
        kor_lepes++;
        eletek = ki.eletek;
        legyozott_ellenfelek = ki.legyozott_ellenfelek;
        pontszam = ki.pontszam;
        elkoltheto_pontok = ki.elkoltheto_pontok;
    }
    kor_vege(eletek, pontszam, elkoltheto_pontok, tornyok, ellenfelek, kori, nev);
}