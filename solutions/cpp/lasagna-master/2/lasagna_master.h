#pragma once
#include <vector>
#include <string>

namespace lasagna_master {

struct amount {
    int noodles;
    double sauce;
};

    int preparationTime(const std::vector<std::string>& layers, int time = 2);
    amount quantities(const std::vector<std::string>& layers);
    void addSecretIngredient(std::vector<std::string>& layers, const std::vector<std::string>& friends_list);
    void addSecretIngredient(std::vector<std::string>& layers, const std::string secret_ingredient);
    std::vector<double> scaleRecipe(const std::vector<double>& amounts, const int portions);
    

}  // namespace lasagna_master
