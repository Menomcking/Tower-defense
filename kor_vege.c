#include <stdio.h>
#include <stdbool.h>
#include "kor_vege.h"
#include "kirajzol.h"
// Ha vége a körnek, akkor itt tud a felhasználó lerakni tornyokat, ha meg vége a játéknak, akkor itt lesz elmentve a játékos megszerzett pontszáma.
void kor_vege(int eletek, int pontszam, int elkoltheto_pontok, Torony *tornyok, Ellenfel *ellenfelek, int kori){
    struct Torony egy_celpontos = {3, 3, 250, "\u02656", 1};
    struct Torony tobb_celpontos = {2, 2, 400, "\u0265C", 3};
    bool vesz_e = true; 
    char valasz;
    while(vesz_e){
        printf("Most tud tornyokat elhelyezni. Szeretne tornokat elhelyezni?(i/n)\n");
        // getchar();
        // getchar();
        scanf("%c", &valasz);
        if(valasz == "i")
        {
            printf("Adja meg a torony sorszámát, amit el szeretne helyezni.(Balról jobbra és fentről lentre kell számolni.)\n");
            int t_sorszam;
            scanf("%d", &t_sorszam);
            printf("Adja meg a torony típusát(e/t): ");
            char tipus = ' ';
            scanf("%c", &tipus);
            if(tipus == "t"){
                tornyok[t_sorszam] = tobb_celpontos;
                elkoltheto_pontok -= tobb_celpontos.ar;
            }
            else if(tipus == "e"){
                tornyok[t_sorszam] = egy_celpontos;
                elkoltheto_pontok -= egy_celpontos.ar;
            }
        }else
            vesz_e = false;
    }
    if(eletek > 1){
        printf("Készen áll a következő körre?(i/n)\n");
        char kovi = ' ';
        scanf("%c", &kovi);
        if(kovi == "i")
            kirajzol(eletek, pontszam, elkoltheto_pontok, tornyok, ellenfelek, kori);
        else
            printf("Vége a játéknak.");
    }else
        printf("Vége a játéknak.");
}