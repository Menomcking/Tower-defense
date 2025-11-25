#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#ifdef _WIN64
    #include <windows.h>
#endif
#include "kirajzol.h"
#include "nevadas.h"

/*
void kor(int eletek, int pontszam, int elkoltheto_pontok, Torony *tornyok, Ellenfel *ellenfelek, int kori){
    if(eletek != 0){
        kirajzol(eletek, pontszam, elkoltheto_pontok, tornyok, ellenfelek, kori);

        kori++;
    }
    else{
        printf("\nVége a körek");
        kor_vege(eletek, pontszam, elkoltheto_pontok, tornyok, ellenfelek, kori);
    }

} */

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
    struct Torony tornyok[8];
    kirajzol(eletek, pontszam, elkoltheto_pontok, tornyok, ellenfelek, kori);
    free(nev);
    return 0;
}