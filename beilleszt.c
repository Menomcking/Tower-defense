#include <stdio.h>
#include "jatek_vege.h"
//Segéd a jatek_vege.c-hez itt hozódik létre a láncolt lista amit használ.
adat *beilleszt(adat *kezdo, adat *uj){
    if(kezdo == NULL || uj -> pont > kezdo -> pont){
        uj -> kov = kezdo;
        return uj;
    }

    adat *mostani = kezdo;
    while(mostani -> kov != NULL && mostani -> kov -> pont >= uj -> pont)
        mostani = mostani -> kov;
    
    uj -> kov = mostani -> kov;
    mostani -> kov = uj;
    return kezdo;
}