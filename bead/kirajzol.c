#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ellenfel_init.h"
#include "kirajzol.h"

//Kirajzolja a térképet a konzolra és itt történik a program nagy része. Addig fut amíg vagy el nem fogy a játékos vagy az ellenfelek élete
void kirajzol(int eletek, int pontszam, int elkoltheto_pontok, Torony *tornyok, Ellenfel *ellenfelek, int kori, int kor_lepes){
    int ti = 0;
    int ei = 0;
    int iter = 0;
    int legyozott_ellenfelek = 0;
    bool ellen_elfogyott = false;
    bool kor_vege_e = false;
    if(legyozott_ellenfelek == 5)
        ellen_elfogyott = true;
    //char lerakott_tornyok[5] = {'T', 'T', 'T', 'T', 'T'};
    int p_ellenfelek[9] = {0};
    while(!kor_vege_e){
        /*for(int i = 9; i >= 0; i--){
            if(p_ellenfelek[9] != 0)
                eletek--;
            if(i > 0)
                p_ellenfelek[i] = p_ellenfelek[i - 1];
            else
                p_ellenfelek[i] = ellenfelek[iter].elet;
        }*/
        for(int i = 0; i < 9; i++){
            printf("\n");
            for(int x = 0; x < 9; x++){
                if(9 - i == 9 - x){
                    printf("%d", p_ellenfelek[ei]);
                    ei++;
                }
                else if((i > 1 && i < 7) && ((i % 2 == 1  && x == i - 2) || (i % 2 == 0 && x == i + 2))){
                    printf("%c", tornyok[ti].icon);
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
        if(kor_lepes < 0){
            //kor(eletek, pontszam, elkoltheto_pontok, tornyok, ellenfelek, kori, kor_lepes + 1)
        }
    }
    if(kor_lepes > -1)
        kor_vege(eletek, pontszam, elkoltheto_pontok, tornyok, ellenfelek, kori);
} 