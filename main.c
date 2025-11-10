#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Ellenfel{
    int elet;
    int pont;
}Ellenfel;

struct Torony{
    int hatotav;
    int sebzes;
    int ar;
    char icon;
}Torony;

void kirajzol(int eletek){
    for(int i = 0; i <= 10; i++){
        printf("\n");
        for(int x = 0; x <= 10; x++){
            if((9 - i) == 9 - x)
                printf("0");
            else if((i % 2 == 1 && x == i - 2) || (i % 2 == 0 && x == i + 2))
                printf("T"); 
            else
                printf(" ");
        }
    }
    printf("\n\n");
    for(int i = 0; i < eletek; i++){
        printf("♥");
    }
} 

void kor(int eletek){
    if(eletek != 0){
        kirajzol(eletek);
    }

}

int main(void){
    printf("Adja meg a játékos nevét:\n");
    char jatekos[10] = "";
    scanf("%s", jatekos);
    int pontszam = 0;
    int eletek = 3;
    kirajzol(eletek);

    return 0;
}