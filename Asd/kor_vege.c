#include <stdio.h>
#include <stdbool.h>
#include "kor_vege.h"
#include "kirajzol.h"
#include "jatek_vege.h"
#include "ellenfel_init.h"
// Ha vége a körnek, akkor itt tud a felhasználó lerakni tornyokat, ha meg vége a játéknak, akkor itt lesz elmentve a játékos megszerzett pontszáma.
void kor_vege(int eletek, int pontszam, int elkoltheto_pontok, Torony *tornyok, Ellenfel *ellenfelek, int kori, char *nev){
    struct Torony egy_celpontos = {3, 3, 250, 'E', 1};
    struct Torony tobb_celpontos = {2, 2, 400, 'Ö', 3};
    bool vesz_e = true; 
    char valasz;
    int legyozott_ellenfelek = 0;
    //Itt mindent megpróbáltam hogy lehessen stringgel válaszolni a kérdésre és azt vizsgálja meg az if, de sehogy se volt hajlandó működni, ezért maradtam a számoknál.
    while(vesz_e){
        printf("Most tud tornyokat elhelyezni. Szeretne tornyokat elhelyezni?(igen: 1/nem: 0)\n");
        int elhelyez_e = 0;
        scanf("%d", &elhelyez_e);
        if(elhelyez_e == 1)
        {
            kirajzol(eletek, pontszam, elkoltheto_pontok, tornyok, ellenfelek, 0, -1, legyozott_ellenfelek);
            printf("Adja meg a torony sorszámát, amit el szeretne helyezni.(Balról jobbra és fentről lentre kell számolni.)\n");
            int t_sorszam = 0;
            scanf("%d", &t_sorszam);
            printf("Adja meg hány célpontos tornyot szeretne lerakni(1/3): %d\n", elkoltheto_pontok);
            int tipus = 0;
            scanf("%d", &tipus);
            if((tipus == 1 && elkoltheto_pontok < egy_celpontos.ar) || (tipus == 3 && elkoltheto_pontok < tobb_celpontos.ar)){
                printf("Nincs elegendő pontja ahoz hogy megvegye ezt a tornyot.");
                vesz_e = false;
            }else if(tipus == 3){
                tornyok[t_sorszam].ar = tobb_celpontos.ar;
                tornyok[t_sorszam].icon = 'Ö';
                tornyok[t_sorszam].hatotav = tobb_celpontos.hatotav;
                tornyok[t_sorszam].sebzes = tobb_celpontos.sebzes;
                tornyok[t_sorszam].max_celpontok = tobb_celpontos.max_celpontok;
                elkoltheto_pontok -= tobb_celpontos.ar;
            }
            else if(tipus == 1){
                tornyok[t_sorszam].ar = egy_celpontos.ar;
                tornyok[t_sorszam].icon = 'E';
                tornyok[t_sorszam].hatotav = egy_celpontos.hatotav;
                tornyok[t_sorszam].sebzes = egy_celpontos.sebzes;
                tornyok[t_sorszam].max_celpontok = egy_celpontos.max_celpontok;
                elkoltheto_pontok -= egy_celpontos.ar;
            }
        }else{
            vesz_e = false;
            printf("Nem vesz ebben a körben tornyokat.\n");
        }
    }
    if(eletek > 1){
        printf("Készen áll a következő körre?(igen: 1/nem: 0)\n");
        int kovi = 0;
        scanf("%d", &kovi);
        if(kovi == 1)
            kor(eletek, pontszam, elkoltheto_pontok, tornyok, ellenfelek, kori + 1, 0, 0, nev);
        else
            printf("Vége a játéknak.\n");
            jatek_vege(pontszam, nev); 
    }else
        printf("Vége a játéknak.\n");
        jatek_vege(pontszam, nev);
}