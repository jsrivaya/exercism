#include "nucleotide_count.h"
#include <iostream>

namespace nucleotide_count {

std::map<char, int> count(std::string_view sequence) {
    std::map<char, int> dna{
        {'A', 0}, {'C', 0}, {'G', 0}, {'T', 0}
    };
    for (const auto& c : sequence) {
        if(dna.find(c) != dna.end()) {
            dna[c]++;
        } else {
            throw std::invalid_argument("Invalid dna sequence");
        }
    }
    return dna;
}

}  // namespace nucleotide_count
