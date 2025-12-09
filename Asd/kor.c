#include <stdio.h>
#include <stdbool.h>
#include "kirajzol.h"
#include "kor_vege.h"

//Itt fut a játék fő része, addig ismételgeti a kirazjolást amíg vége nincs a körnek.
void kor(int eletek, int pontszam, int elkoltheto_pontok, Torony *tornyok, Ellenfel *ellenfelek, int kori, int kor_lepes, int legyozott_ellenfelek, char *nev){
    while(eletek > 3){
        kirajzol(eletek, pontszam, elkoltheto_pontok, tornyok, ellenfelek, kori, kor_lepes, legyozott_ellenfelek);
        Ellenfel temp;
        Ellenfel temp2;
        if(legyozott_ellenfelek == 5)
            kor_vege(eletek, pontszam, elkoltheto_pontok, tornyok, ellenfelek, kori, nev);
        
    }
}