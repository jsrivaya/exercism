#include "kindergarten_garden.h"
#include <map>
#include <array>

namespace kindergarten_garden {
std::map<char, Plants> get_plant_code {
    {'G', grass},
    {'C', clover},
    {'R', radishes},
    {'V', violets}
};
    
enum Students {
    Alice = 0,
    Bob,
    Charlie,
    David,
    Eve,
    Fred,
    Ginny,
    Harriet,
    Ileana,
    Joseph,
    Kincaid,
    Larry,
    Count
};

std::map<std::string, Students> get_student_index {
    {"Alice", Alice},
    {"Bob", Bob},
    {"Charlie", Charlie},
    {"David", David},
    {"Eve", Eve},
    {"Fred", Fred},
    {"Ginny", Ginny},
    {"Harriet", Harriet},
    {"Ileana", Ileana},
    {"Joseph", Joseph},
    {"Kincaid", Kincaid},
    {"Larry", Larry}
};

std::array<Plants, 4> plants(const std::string& garden, const std::string& student) {
    std::array<Plants, 4> student_garden;

    // 1. find student index
    auto index = get_student_index[student];
    // 2. first two plants: string[0+(2*index)] and string[1+(2*index)]
    student_garden[0] = get_plant_code[garden[0+(2*index)]];
    student_garden[1] = get_plant_code[garden[1+(2*index)]];
    // 3. move to second row (find \n)
    auto second_row_base = garden.find_first_of('\n') + 1;
    // 4. second two pants: string[0+(2*index)] and string[1+(2*index)]
    student_garden[2] = get_plant_code[garden[second_row_base + (2*index)]];
    student_garden[3] = get_plant_code[garden[second_row_base + 1 + (2*index)]];

    return student_garden;
}

}  // namespace kindergarten_garden
