#include "eliuds_eggs.h"

namespace chicken_coop {

unsigned int positions_to_quantity(unsigned int dec){
    unsigned int eggs = 0;
    // Brian Kernighan’s algorithm: using LSB bit shifting
    while(dec) {
        dec &= dec - 1; // Clears the lowest set bit
        eggs++;
    }
    return eggs;
}

}  // namespace chicken_coop
