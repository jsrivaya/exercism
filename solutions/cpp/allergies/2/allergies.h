#pragma once
#include <string>
#include <unordered_set>
#include <vector>
namespace allergies {

class allergy_test {
  public:
    allergy_test(int);
    bool is_allergic_to(const std::string&) const;
    std::unordered_set<std::string> get_allergies() const;
  private:
    std::unordered_set<std::string> allergies;
};

}  // namespace allergies
