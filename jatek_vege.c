#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "kor_vege.h"
#include "jatek_vege.h"
#include "temp_rst.h"
#include "kirajzol.h"
#include "ellenfel_init.h"
#include "debugmalloc.h"
#include "beilleszt.h"
// A játék végén beilleszti a megfelelő helyre a dicsőséglistába a játékos által elért pontszámot és a megadott nevet.
void jatek_vege(int pontok, char *neve){
    FILE *fp = fopen("discoseg_lista.txt", "r");
    adat *kezdo = NULL;

    if(fp){
        char nevbuffer[50];
        char pontbuffer[10];

        while (1) {
            if(!fgets(nevbuffer, sizeof(nevbuffer), fp))
                break;
            
            nevbuffer[strcspn(nevbuffer, "\r\n")] = '\0';

            if(!fgets(pontbuffer, sizeof(pontbuffer), fp))
                pontbuffer[0] = '\0';
            
            int pnt = atoi(pontbuffer);

            adat *data = (adat*) malloc(sizeof(adat));
            if(!data){
                perror("Malloc nem sikerült");
                break;
            }
            strncpy(data -> nev, nevbuffer, 49);
            data -> nev[49] = '\0';
            data -> pont = pnt;
            data -> kov = NULL;
            kezdo = beilleszt(kezdo, data);
        }
        fclose(fp);
    }

    adat *jatekos = (adat*) malloc(sizeof(adat));
    if(!jatekos){
        perror("Malloc nem sikerült");
        adat *t = kezdo;
        while(t){
            adat *n = t -> kov;
            free(t);
            t = n;
        }
        return;
    }
    strncpy(jatekos -> nev, neve, 49);
    jatekos -> nev[49] = '\0';
    jatekos -> pont = pontok;
    jatekos -> kov = NULL;
    kezdo = beilleszt(kezdo, jatekos);

    fp = fopen("discoseg_lista.txt", "w");
    if(!fp){
        perror("Nem sikerült megnyitni a fájlt az íráshoz.");
        adat *t = kezdo;
        while(t){
            adat *n = t -> kov;
            free(t);
            t = n;
        }
        return;
    }

    for(adat *c = kezdo; c != NULL; c = c -> kov){
        fprintf(fp, "%s\n", c -> nev);
        fprintf(fp, "%d\n", c -> pont);
    }
    fclose(fp);

    adat *t = kezdo;
    while(t){
        adat *n = t-> kov;
        free(t);
        t = n;
    }
}