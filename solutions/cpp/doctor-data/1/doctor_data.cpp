#include "doctor_data.h"

namespace heaven {
    std::string get_older_bob(const Vessel vessel_1, const Vessel vessel_2) {
        return (vessel_1.generation < vessel_2.generation) ? vessel_1.name : vessel_2.name;
    }
    bool in_the_same_system(const Vessel vessel_1, const Vessel vessel_2) {
        return vessel_1.current_system == vessel_2.current_system;
    }
}