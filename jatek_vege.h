#ifndef JATEK_VEGE_H
#define JATEK_VEGE_H
    typedef struct Adat{
    char nev[50];
    int pont;
    struct Adat *kov;
    }adat;
    void jatek_vege(int pontok, char *neve);
#endif