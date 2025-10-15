#include "allergies.h"
#include <cmath>
#include <iostream>
#include <array>
#include <map>
namespace allergies {
enum code {
    EGGS,
    PEANUTS,
    SHELLFISH,
    STRAWBERRIES,
    TOMATOES,
    CHOCOLATE,
    POLLEN,
    CATS
};
std::array<code, 8> codes{EGGS, PEANUTS, SHELLFISH, STRAWBERRIES, TOMATOES, CHOCOLATE, POLLEN, CATS};
std::map<code, std::string> code_to_string {
    {EGGS,"eggs"},
    {PEANUTS,"peanuts"},
    {SHELLFISH,"shellfish"},
    {STRAWBERRIES,"strawberries"},
    {TOMATOES,"tomatoes"},
    {CHOCOLATE,"chocolate"},
    {POLLEN,"pollen"},
    {CATS,"cats"}
};
std::map<std::string,code> string_to_code {
    {"eggs",EGGS},
    {"peanuts",PEANUTS},
    {"shellfish",SHELLFISH},
    {"strawberries",STRAWBERRIES},
    {"tomatoes",TOMATOES},
    {"chocolate",CHOCOLATE},
    {"pollen",POLLEN},
    {"cats",CATS}
};
    
allergy_test::allergy_test(int value) {
    for(const auto& c : codes) {
        allergies.emplace(allergies.begin()+c, value%2);
        value/=2;
    }
}
    
bool allergy_test::is_allergic_to(const std::string& allergy) const {
    try {
        return allergies.at(string_to_code.at(allergy));
    } catch (std::out_of_range& e) {}
    return false;
}

std::unordered_set<std::string> allergy_test::get_allergies() const {
    std::unordered_set<std::string> result{};
    for (const auto& c : codes) {
        if (allergies.at(c)) result.emplace(code_to_string.at(c));
    }
    return result;
}
}  // namespace allergies
