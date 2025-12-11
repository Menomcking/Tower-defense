#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "kor_vege.h"
#include "jatek_vege.h"
#include "temp_rst.h"
#include "kirajzol.h"
#include "ellenfel_init.h"
// A játék végén beilleszti a megfelelő helyre a dicsőséglistába a játékos által elért pontszámot és a megadott nevet.
void jatek_vege(int pontok, char *neve){
    FILE *fp;
    char *pontszam = NULL;
    fp = fopen("dicsoseg_lista.txt", "r");
    if (fp == NULL){
        perror("A fájl megnyitása sikertelen.");
        return;
    }else
        printf("A fájl sikeresen megnyitva.");

    adat tomb[10];
    adat temp = {" ", 0};
    adat temp2 = {" ", 0};
    for(int i = 0; i < 10; i++){
        fgets(tomb[i].nev, strlen(neve), fp);
        fgets(pontszam, __INT_MAX__, fp);
        tomb[i].pont = atoi(pontszam);
        if(pontok > tomb[i].pont && i != 9){
            temp.nev = tomb[i].nev;
            temp.pont = tomb[i].pont;
            tomb[i].nev = neve;
            tomb[i].pont = pontok;
            pontok = 0;
        }else if(temp.pont > tomb[i].pont && i != 9){
            temp2.nev = temp.nev;
            temp2.pont = temp.pont;
            tomb[i].nev = temp.nev;
            tomb[i].pont = temp.pont;
            temp.nev = temp2.nev;
            temp.pont = temp2.pont;
            temp_rst(&temp2);
        if(i == 9 && temp.pont > tomb[9].pont){
            tomb[9].nev = temp.nev;
            tomb[9].pont = temp.pont;
            temp_rst(&temp);
        }else if(i == 9 && pontok > tomb[9].pont){
            tomb[9].nev = neve;
            tomb[9].pont = pontok;
            }
        }
        //A fájl feltöltése adatokkal
        fprintf(fp, "%s", tomb[0].nev);
        fprintf(fp, "\n");
        fprintf(fp, "%s", tomb[0].pont);
        fprintf(fp, "\n");
        fclose(fp);
        fp = fopen("discoseg_lista.txt", "a");
        for(int i = 1; i < 10; i++){
            fprintf(fp, "%s", tomb[i].nev);
            fprintf(fp, "\n");
            fprintf(fp, "%s", tomb[i].pont);
            fprintf(fp, "\n");
        }
        fclose(fp);
    }
}