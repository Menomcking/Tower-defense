#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Ellenfel{
    int elet;
    int pont;
}Ellenfel;

typedef struct Torony{
    int hatotav;
    int sebzes;
    int ar;
    int max_celpontok;
    char icon[7];
}Torony;
// A felhasználó itt tudja megadni a nevét a toplistához.
char *nevadas(int nevhossz){
    char *s = (char*)malloc((nevhossz + 1) * sizeof(char));
    printf("Adja meg a játékos nevét: \n");
    scanf("%s", s);
    return s;
}
// Az ellenfeleket itt generálja le az eltelt körtől függő élettel és ponttal rendelkeznek.(a számok nem véglegesek)
struct Ellenfel *ellenfel_init(int korszam, Ellenfel *ellenfelek){
    struct Ellenfel ellen = {3 * korszam, 50 * korszam};
    for(int i = 0; i < 5; i++){
        ellenfelek[i] = ellen;
    }
    return ellenfelek;
}
//Krajzolja a térképet a konzolra és itt történik a program nagy része. Addig fut amíg vagy el nem fogy a játékos vagy az ellenfelek élete
void kirajzol(int eletek, int pontszam, int elkoltheto_pontok, Torony *tornyok, Ellenfel *ellenfelek, int kori){
    int ti = 0;
    int ei = 0;
    int iter = 0;
    int legyozott_ellenfelek = 0;
    bool ellen_elfogyott = false;
    bool kor_vege_e = false;
    if (legyozott_ellenfelek == 0)
        kor_vege_e = true;
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
// Ha vége a körnek, akkor itt tud a felhasználó lerakni tornyokat, ha meg vége a játéknak, akkor itt lesz elmentve a játékos megszerzett pontszáma.
void kor_vege(int eletek, int pontszam, int elkoltheto_pontok, Torony *tornyok, Ellenfel *ellenfelek, int kori){
    struct Torony egy_celpontos = {3, 3, 250, "\u02656", 1};
    struct Torony tobb_celpontos = {2, 2, 400, "\u0265C", 3};
    bool vesz_e = true; 
    while(vesz_e){
            printf("Most tud tornyokat elhelyezni. Szeretne tornokat elhelyezni?(i/n)");
            char valasz = ' ';
            scanf("%c", &valasz);
            if(valasz == "i")
            {
                printf("Adja meg a torony sorszámát, amit el szeretne helyezni.(Balról jobbra és fentről lentre kell számolni.)");
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
        if(eletek == 0)
            printf("Vége a játéknak.");
        else{
            printf("Készen áll a következő körre?(i/n)");
            char kovi = ' ';
            scanf("%c", &kovi);
            if(kovi == "i")
                kirajzol(eletek, pontszam, elkoltheto_pontok, tornyok, ellenfelek, kori);
            else
                printf("Vége a játéknak.");


        }
}

int main(void){
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