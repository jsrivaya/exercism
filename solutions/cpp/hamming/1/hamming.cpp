#include "hamming.h"
#include <iostream>
#include <iterator>
namespace hamming {

int compute(std::string_view original, std::string_view copy) {
    if (original.length() != copy.length()) {
        throw std::domain_error("unequal length");
    }
    
    int hamming_distance = 0;
    for(size_t i=0; i<original.length(); ++i) {
        if (original[i] != copy[i]) {
            ++hamming_distance;
        }
    }
    return hamming_distance;
}

}  // namespace hamming
