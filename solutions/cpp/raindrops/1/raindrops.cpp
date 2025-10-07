#include "raindrops.h"

namespace raindrops {

std::map<int, std::string> sounds = {
    {3, "Pling"},
    {5, "Plang"},
    {7, "Plong"}
};

std::string convert(unsigned raindrops){
    std::string result = "";

    if((raindrops % 3 != 0) &&
        (raindrops % 5 != 0) &&
        (raindrops % 7 != 0)) {
        return std::to_string(raindrops);
    }
    if(raindrops % 3 == 0) {
        result += sounds[3];
    }
    if(raindrops % 5 == 0) {
        result += sounds[5];
    }
    if(raindrops % 7 == 0) {
        result += sounds[7];
    }

    return result;
}

}  // namespace raindrops
