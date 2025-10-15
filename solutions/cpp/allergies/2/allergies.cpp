#include "allergies.h"
#include <cmath>
#include <map>
namespace allergies {
enum allergen {
    EGGS=1,
    PEANUTS=2,
    SHELLFISH=4,
    STRAWBERRIES=8,
    TOMATOES=16,
    CHOCOLATE=32,
    POLLEN=64,
    CATS=128
};

std::map<allergen, std::string> allergens {
    {EGGS,"eggs"},
    {PEANUTS,"peanuts"},
    {SHELLFISH,"shellfish"},
    {STRAWBERRIES,"strawberries"},
    {TOMATOES,"tomatoes"},
    {CHOCOLATE,"chocolate"},
    {POLLEN,"pollen"},
    {CATS,"cats"}
};
    
allergy_test::allergy_test(int value) {
    for(const auto& a : allergens) {
        if((value & a.first) == a.first) {
            allergies.emplace(a.second);
        }
    }
}
    
bool allergy_test::is_allergic_to(const std::string& allergy) const {
    return allergies.count(allergy);
}

std::unordered_set<std::string> allergy_test::get_allergies() const {
    return allergies;
}
}  // namespace allergies
