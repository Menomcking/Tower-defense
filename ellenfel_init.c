#include <stdio.h>
#include "ellenfel_init.h"
// Az ellenfeleket itt generálja le az eltelt körtől függő élettel és ponttal rendelkeznek.(a számok nem véglegesek)
struct Ellenfel *ellenfel_init(int korszam, Ellenfel *ellenfelek){
    struct Ellenfel ellen = {3 * korszam, 50 * korszam};
    for(int i = 0; i < 5; i++){
        ellenfelek[i].elet = ellen.elet;
        ellenfelek[i].pont = ellen.pont;
    }
    return ellenfelek;
}