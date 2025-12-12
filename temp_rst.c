#include <stdio.h>
#include "temp_rst.h"
#include "jatek_vege.h"
#include <string.h>
// A jatek_vege.c fájlban beállítja az alapértelmezett értékeket az adott adat típusú változónak.
void temp_rst(adat *temp){
    strcmp(temp -> nev, " ");
    temp -> pont = 0;
}