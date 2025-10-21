#include "protein_translation.h"
#include<unordered_map>
namespace protein_translation {

/* Codon	Amino Acid*/
std::unordered_map<std::string, std::string> amino_acid {
    {"AUG", "Methionine"},
    {"UUU", "Phenylalanine"},
    {"UUC", "Phenylalanine"},
    {"UUA", "Leucine"},
    {"UUG", "Leucine"},
    {"UCU", "Serine"},
    {"UCC", "Serine"},
    {"UCA", "Serine"},
    {"UCG", "Serine"},
    {"UAU", "Tyrosine"},
    {"UAC", "Tyrosine"},
    {"UGU", "Cysteine"},
    {"UGC", "Cysteine"},
    {"UGG", "Tryptophan"},
    {"UAA", "STOP"},
    {"UAG", "STOP"},
    {"UGA", "STOP"}
};

std::string get_codon_at(const std::string& rna, const size_t& index){
    return index < rna.size() ? rna.substr(index, 3) : "";
}

std::string get_protein(const std::string& codon){ 
    return amino_acid.find(codon)!=amino_acid.end() ? amino_acid.at(codon) : "STOP";
}

std::vector<std::string> proteins(const std::string& rna){
    std::vector<std::string> final_proteins;

    for(size_t i=0; i<rna.length(); i+=3){
        auto codon = get_codon_at(rna, i);
        auto protein = get_protein(codon);
        
        if(protein == "STOP") break;
        final_proteins.emplace_back(protein);
    }
    return final_proteins;
}

}  // namespace protein_translation
