#include <stdio.h>
#include <stdlib.h>
#include "nevadas.h"

// A felhasználó itt tudja megadni a nevét a toplistához.
char *nevadas(int nevhossz){
    char *s = (char*)malloc((nevhossz + 1) * sizeof(char));
    printf("Adja meg a játékos nevét: \n");
    scanf("%s", s);
    return s;
}