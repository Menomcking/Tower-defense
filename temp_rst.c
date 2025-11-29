#include <stdio.h>
#include "temp_rst.h"
#include "jatek_vege.h"
// A jatek_vege.c fájlban beállítja az alapértelmezett értékeket az adott adat típusú változónak.
void temp_rst(adat *temp){
    temp -> nev = " ";
    temp -> pont = 0;
}