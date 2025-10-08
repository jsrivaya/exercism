#include "lasagna_master.h"
#include <cmath>
#include <iostream>

namespace lasagna_master {

    int preparationTime(const std::vector<std::string>& layers, int time) {
        return layers.size() * time;
    }

    amount quantities(const std::vector<std::string>& layers) {
        amount amount_gr = {0, 0.0};
        for (auto layer : layers) {
            if(layer == "noodles"){
                amount_gr.noodles += 50;                 
            } else if(layer == "sauce"){
                amount_gr.sauce += 0.2;
            }  
        }
        return amount_gr;
    }

    void addSecretIngredient(std::vector<std::string>& layers, const std::vector<std::string>& friends_list){
        layers.at(layers.size()-1) = friends_list.back();
    }
    void addSecretIngredient(std::vector<std::string>& layers, const std::string secret_ingredient) {
        layers.at(layers.size()-1) = secret_ingredient;
    }

    std::vector<double> scaleRecipe(const std::vector<double>& amounts, const int portions) {
        std::vector<double> scaled_recipe;
        for (auto& amount : amounts) { 
            auto portion = amount / 2;
            scaled_recipe.emplace_back(portion * portions);
        }
        return scaled_recipe;
    }

}  // namespace lasagna_master
