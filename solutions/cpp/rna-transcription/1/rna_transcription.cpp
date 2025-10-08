#include "rna_transcription.h"
#include <map>

namespace rna_transcription {

std::map<char,char> dna_to_rna = {
    {'A', 'U'},
    {'C', 'G'},
    {'G', 'C'},
    {'T', 'A'}
};

char to_rna(const char c) {
    return dna_to_rna[c];
}

std::string to_rna(const std::string& sequence) {
    std::string rna = "";
    for (const auto& c : sequence) {
        rna += to_rna(c);
    }
    return rna;
}

}  // namespace rna_transcription
