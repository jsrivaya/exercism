#include "grade_school.h"
#include <iostream>

namespace grade_school {

    std::map<int, std::vector<std::string>> school::roster() const{
        return school_roster;
    }
    void school::add(const std::string& student, int level){
        const auto& it =
            std::lower_bound(school_roster[level].begin(), school_roster[level].end(), student);
        school_roster[level].emplace(it, student);
    }
    std::vector<std::string> school::grade(int level) const{
        try {
            return school_roster.at(level);
        } catch (const std::out_of_range& e) {
            std::cerr << "Grade level not found: " << e.what() << std::endl;
            return std::vector<std::string>{};
        }
    }

}  // namespace grade_school
