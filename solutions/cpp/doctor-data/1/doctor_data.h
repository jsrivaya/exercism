#pragma once

#include<string>

namespace star_map {
    enum class System {
        BetaHydri,
        Sol,
        EpsilonEridani,
        AlphaCentauri,
        DeltaEridani,
        Omicron2Eridani
    };
}; // namespace-star_map

namespace heaven {
  class Vessel {
    public:
    Vessel(const std::string name, const int generation, star_map::System current_system = star_map::System::Sol) : name(name), generation(generation), current_system(current_system){};
    Vessel replicate(const std::string name) { return Vessel(name, generation + 1, current_system); };
    void make_buster(){ busters++; };
    bool shoot_buster(){
        if (busters > 0) {
            busters--;
            return true;
        }
        return false;
    };

    std::string name;
    int generation;
    star_map::System current_system;
    int busters = 0;
  };

    std::string get_older_bob(const Vessel, const Vessel);
    bool in_the_same_system(const Vessel, const Vessel);
}; // namespace-heaven
