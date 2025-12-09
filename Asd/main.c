#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#ifdef _WIN64
    #include <windows.h>
#endif
#include "kirajzol.h"
#include "nevadas.h"
#include "kor_vege.h"
#include "debugmalloc.h"

int main(void){
    #ifdef _WIN64
        SetConsoleCP(65001);
        SetConsoleOutputCP(65001);
    #endif 
    printf("Adja meg hány betűből fog állni a játékosnév: \n");
    int nevhossz;
    scanf("%d", &nevhossz);
    char *nev = nevadas(nevhossz);
    int pontszam = 0;
    int eletek = 3;
    int elkoltheto_pontok = 500;
    int kori = 1;
    struct Ellenfel ellenfelek[5];
    struct Torony tornyok[5];
    for(int i = 0; i < 5; i++){
        tornyok[i].ar = 0;
        tornyok[i].hatotav = 0;
        tornyok[i].ar = 0;
        tornyok[i].sebzes = 0;
        tornyok[i].icon = 'T';
    }
    kor_vege(eletek, pontszam, elkoltheto_pontok, tornyok, ellenfelek, kori, nev);
    free(nev);
    return 0;
}