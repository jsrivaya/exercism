#include "speedywagon.h"

namespace speedywagon {

// Enter your code below:
bool connection_check(const pillar_men_sensor* sensor) {
    return sensor != nullptr;
}

int activity_counter(const pillar_men_sensor* sensors, const int capacity) {
    int total_activity = 0;
    for (auto i = 0; i<capacity; i++) {
        total_activity += sensors->activity;
        ++sensors;
    }
    return total_activity;
}

bool alarm_control(const pillar_men_sensor* sensor) {
    if(sensor == nullptr || sensor->activity <= 0) {
        return false;
    }
    return true;
}

bool uv_alarm(pillar_men_sensor* sensor) {
    if(sensor == nullptr) {
        return false;
    }
    auto uv_light = uv_light_heuristic(&sensor->data);

    if(uv_light > sensor->activity) {
        return true;
    }
    
    return false;
}
    
// Please don't change the interface of the uv_light_heuristic function
int uv_light_heuristic(std::vector<int>* data_array) {
    double avg{};
    for (auto element : *data_array) {
        avg += element;
    }
    avg /= data_array->size();
    int uv_index{};
    for (auto element : *data_array) {
        if (element > avg) ++uv_index;
    }
    return uv_index;
}

}  // namespace speedywagon
