#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ellenfel_init.h"
#include "kirajzol.h"
#include "kor.h"
#include "kor_vege.h"

//Kirajzolja a térképet a konzolra és itt történik a program nagy része. Addig fut amíg vagy el nem fogy a játékos vagy az ellenfelek élete
kimenet kirajzol(int eletek, int pontszam, int elkoltheto_pontok, Torony *tornyok, Ellenfel *ellenfelek, int kori, int kor_lepes, int legyozott_ellenfelek){
    int iter = 0;
    int p_ellenfelek[9] = {0};
    const int osszes_ellenfel = 5;
    bool kezdo_szabad = true;
    int torony_helyek[5][2]= {
        {3, 1},
        {1, 3},
        {5, 4},
        {2, 5},
        {6, 6}
    };
    if(kor_lepes > -1){
        for(int i = 0; i < 5; i++){
            int tx = torony_helyek[i][0];
            int ty = torony_helyek[i][1];

            int p1 = ty;
            int p2 = ty -1;
            int p3 = ty +1;
            int max_celpont = tornyok[i].max_celpontok; 
            int eltalaltak = 0;
            
            for(int j = 0; j < osszes_ellenfel; j++){
                if(ellenfelek[j].elet <= 0)
                    continue;
                if(ellenfelek[j].pozicio == p1 || ellenfelek[j].pozicio == p2 || ellenfelek[j].pozicio == p3){
                    ellenfelek[j].elet -= tornyok[i].sebzes;
                    eltalaltak++;

                    if(ellenfelek[j].elet <= 0){
                        ellenfelek[j].elet = 0;
                        legyozott_ellenfelek++;
                        pontszam += ellenfelek[j].pont;
                        elkoltheto_pontok += ellenfelek[j].pont;
                    }
                    if(eltalaltak >= max_celpont)
                        break;
                }
            }


        }
        for(int i = 0; i < osszes_ellenfel; i++){
            if(ellenfelek[i].elet > 0 &&  ellenfelek[i].pozicio >= 0) {
                ellenfelek[i].pozicio++;

                if(ellenfelek[i].pozicio >= 9 && ellenfelek[i].elet > 0){
                    eletek--;
                    ellenfelek[i].elet = 0;
                    legyozott_ellenfelek++;
                }
            }
        }
       
        for(int i = 0; i < osszes_ellenfel; i++){
            if(ellenfelek[i].pozicio == 0 && ellenfelek[i].elet > 0){
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
        for(int i = 0; i < 9; i++)
            p_ellenfelek[i] = 0;
        for(int i = 0; i < osszes_ellenfel; i++){
            if(ellenfelek[i].pozicio >= 0 && ellenfelek[i].pozicio < 9 && ellenfelek[i].elet > 0)
                p_ellenfelek[ellenfelek[i].pozicio] = ellenfelek[i].elet;
        }
    }    
    int ei = 0;
    int ti = 0;
    //Térkép kirajzolása
    printf("\n--- %d. kör | %d. lépés ---\n", kori, kor_lepes);
    for(int y = 0; y < 9; y++){
        printf("\n");
        for(int x = 0; x < 9; x++){
            if(9 - y == 9 - x){
                printf("%d", p_ellenfelek[y]);
                ei++;
            }
            else if((y > 1 && y < 7) && ((y % 2 == 1  && x == y - 2) || (y % 2 == 0 && x == y + 2))){
                //if(ti >= 0 && ti < 5 && tornyok[ti].ar > 0)
                    printf("%c", tornyok[ti].icon);
                    ti++;
                /*else
                    printf("T"); */
                
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

    kimenet ki = {eletek, legyozott_ellenfelek, pontszam, elkoltheto_pontok};

    return ki;

} 