#include "resistor_color.h"

#include <map>

namespace resistor_color {

std::map<std::string, int> codes = {
    {"black", 0},
    {"brown", 1},
    {"red", 2},
    {"orange", 3},
    {"yellow", 4},
    {"green", 5},
    {"blue", 6},
    {"violet", 7},
    {"grey", 8},
    {"white", 9},
};
std::vector<std::string> color_list = {
    "black", "brown", "red", "orange", "yellow",
    "green", "blue", "violet", "grey", "white"
};
    
int color_code(const std::string& color) {
    auto it = codes.find(color);
    return (it != codes.end()) ? it->second : -1;
}
    
std::vector<std::string> colors () {
    return color_list;
}

}  // namespace resistor_color
