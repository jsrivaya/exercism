#pragma once
#include <string>
#include <vector>
#include <map>

namespace grade_school {

class school {
    public:
    school() {};
    std::map<int, std::vector<std::string>> roster() const;
    void add(const std::string&, int);
    std::vector<std::string> grade(int) const;

    private:
    std::map<int, std::vector<std::string>> school_roster;
};

}  // namespace grade_school
