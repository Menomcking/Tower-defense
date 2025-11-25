#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ellenfel_init.h"
#include "kirajzol.h"

//Kirajzolja a térképet a konzolra és itt történik a program nagy része. Addig fut amíg vagy el nem fogy a játékos vagy az ellenfelek élete
void kirajzol(int eletek, int pontszam, int elkoltheto_pontok, Torony *tornyok, Ellenfel *ellenfelek, int kori){
    int ti = 0;
    int ei = 0;
    int iter = 0;
    int legyozott_ellenfelek = 0;
    bool ellen_elfogyott = false;
    bool kor_vege_e = false;
    if (legyozott_ellenfelek == 0)
        kor_vege_e = false;
    else if(legyozott_ellenfelek == 5)
        ellen_elfogyott = true;
    char lerakott_tornyok[8] = {'T', 'T', 'T', 'T', 'T', 'T', 'T', 'T'};
    int p_ellenfelek[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    while(kor_vege_e == false){
        for(int i = 8; i >= 0; i--){
            if(p_ellenfelek[8] != 0)
                eletek--;
            if(i > 0)
                p_ellenfelek[i] = p_ellenfelek[i - 1];
            else
                p_ellenfelek[i] = ellenfelek[iter].elet;
        }
        for(int i = 0; i < 8; i++){
            if(tornyok[i].ar != NULL)
                lerakott_tornyok[i] = tornyok[i].icon;
        }
        ellenfelek = ellenfel_init(kori, ellenfelek);
        for(int i = 0; i <= 10; i++){
            printf("\n");
            for(int x = 0; x <= 10; x++){
                if((9 - i) == 9 - x){
                    printf("%d", p_ellenfelek[ei]);
                    ei++;
                }
                else if(((i % 2 == 1 && x == i - 2) || (i % 2 == 0 && x == i + 2))){
                    printf("%c", lerakott_tornyok[ti]); 
                    ti++;
                }
                else
                    printf(" ");
            }
        }
        printf("\n\n");
        for(int i = 0; i < eletek; i++){
            printf("\u2665");
        }
        printf("\n");
    }
    kor_vege(eletek, pontszam, elkoltheto_pontok, tornyok, ellenfelek, kori);
} 