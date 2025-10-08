#include "grade_school.h"
#include <iostream>

namespace grade_school {

    std::map<int, std::vector<std::string>> school::roster() const{
        return school_roster;
    }
    void school::add(const std::string& student, int level){
        if(school_roster.find(level) == school_roster.end()) {
            school_roster.emplace(level, std::vector<std::string>{student});
            return;
        }
        std::vector<std::string>& grade = school_roster.at(level);
        const auto& it = std::lower_bound(grade.begin(), grade.end(), student);
        grade.emplace(it, student);
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
