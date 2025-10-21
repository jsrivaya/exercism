#include "eliuds_eggs.h"

namespace chicken_coop {

unsigned int positions_to_quantity(unsigned int dec){
    unsigned int eggs = 0;
    while(dec) {
        eggs += dec%2;
        dec/=2;
    }
    return eggs;
}

}  // namespace chicken_coop
