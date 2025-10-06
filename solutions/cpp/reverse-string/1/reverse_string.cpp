#include "reverse_string.h"
#include <iostream>
namespace reverse_string {

std::string reverse_string(const std::string s) {
    if (s.empty()) {
        return s;
    }
    std::string reversed_s = "";
    for(auto itr = s.end()-1; itr >= s.begin(); --itr) {
        reversed_s += *itr;
    }
    return reversed_s;
}

}  // namespace reverse_string
