#include "power_of_troy.h"

namespace troy {
void give_new_artifact(human& person, const std::string new_artifact) {
    person.possession = std::make_unique<artifact>(artifact(new_artifact));
}

void exchange_artifacts(std::unique_ptr<artifact>& artifact_1,
                        std::unique_ptr<artifact>& artifact_2) {
    std::swap(artifact_1, artifact_2);
}

void manifest_power(human& person, std::string new_power) {
    person.own_power = std::make_shared<power>(power(new_power));
}

void use_power(human& caster, human& target){
    target.influenced_by = caster.own_power;
}

int power_intensity(human& person){
    return person.own_power == nullptr ? 0 : person.own_power.use_count();
}  
}  // namespace troy
