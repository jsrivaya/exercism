#include "beer_song.h"

#include <sstream>
namespace beer_song {

const std::string v0 = "No more bottles of beer on the wall, no more bottles of beer.\nGo to the store and buy some more, 99 bottles of beer on the wall.\n";

const std::string v1_0 = "1 bottle of beer on the wall.\n";
const std::string v1 = "1 bottle of beer on the wall, ";
const std::string v1_2 = "1 bottle of beer.\n";
const std::string v1_3 = "Take it down and pass it around, no more bottles of beer on the wall.\n";

const std::string v2 = " bottles of beer on the wall, ";
const std::string v3 = " bottles of beer.\n";
const std::string v4 = "Take one down and pass it around, ";
const std::string v5 = " bottles of beer on the wall.\n";

std::string verse(int n) {
    std::ostringstream value;

    if (n >1){
        value << n << v2 << n << v3 << v4;
        if(n == 2) {
            value << v1_0;
        } else {
            value << n-1 << v5;
        }
    } else if (n == 1) {
        value << v1 << v1_2 << v1_3;
    } else {
        value << v0;
    }
    return value.str();
}
    
std::string sing(int n1, int n2) {
    std::ostringstream value;
    while (n1 >= n2) {
        value << verse(n1);
        if (n1 != n2) {
            value << "\n";
        }
        --n1;
    }
    return value.str();
}

}  // namespace beer_song
