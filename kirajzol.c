#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ellenfel_init.h"
#include "kirajzol.h"
#include "kor.h"
#include "kor_vege.h"

//Kirajzolja a térképet a konzolra és itt történik a program nagy része. Addig fut amíg vagy el nem fogy a játékos vagy az ellenfelek élete
int kirajzol(int eletek, int pontszam, int elkoltheto_pontok, Torony *tornyok, Ellenfel *ellenfelek, int kori, int kor_lepes, int legyozott_ellenfelek){
    int iter = 0;
    int p_ellenfelek[9] = {0};
    const int osszes_ellenfel = 5;
    bool kezdo_szabad = true;
    if(kori > -1){
        for(int i = 0; i < osszes_ellenfel; i++){
            if(ellenfelek[i].elet > 0) {
                ellenfelek[i].pozicio++;

                if(ellenfelek[i].pozicio >= 9){
                    eletek--;
                    ellenfelek[i].elet = 0;
                    legyozott_ellenfelek++;
                }
            }
        }
       
        for(int i = 0; i < osszes_ellenfel; i++){
            if(ellenfelek[i].pozicio == 0){
                kezdo_szabad = false;
                break;
            }
        }
        if(kezdo_szabad){
            for(int i = 0; i < osszes_ellenfel; i++){
                if(ellenfelek[i].pozicio == -1 && ellenfelek[i].elet > 0){
                    ellenfelek[i].pozicio = 0;
                    break;
                }
            }
        }
        for(int i = 0; i < osszes_ellenfel; i++){
            if(ellenfelek[i].pozicio >= 0 && ellenfelek[i].pozicio < 9 && ellenfelek[i].elet > 0)
                p_ellenfelek[ellenfelek[i].pozicio] = ellenfelek[i].elet;
        }
    }    
    int ti = 0;
    int ei = 0;
    //Térkép kirajzolása
    printf("\n--- %d. kör | %d. lépés ---\n", kori, kor_lepes);
    for(int y = 0; y < 9; y++){
        printf("\n");
        for(int x = 0; x < 9; x++){
            if(9 - y == 9 - x){
                printf("%d", p_ellenfelek[ei]);
                ei++;
            }
            else if((y > 1 && y < 7) && ((y % 2 == 1  && x == y - 2) || (y % 2 == 0 && x == y + 2))){
                if(tornyok[ti].ar == 0)
                    printf("T");
                else
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

    return legyozott_ellenfelek;

} 