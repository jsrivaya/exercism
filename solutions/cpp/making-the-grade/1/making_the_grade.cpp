#include <array>
#include <sstream>
#include <string>
#include <vector>

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
    std::vector<int> adjusted_scores;
    for (const auto& score : student_scores) {
        adjusted_scores.emplace_back(score);
    }
    return adjusted_scores;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
    auto number_of_failed_students = 0;
    for (const auto& score : student_scores) {
        if (score <=40 ) {
            number_of_failed_students ++;
        }
    }
    return number_of_failed_students;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
    const auto& failing_score = 40;
    const auto& spacer = (highest_score - failing_score) / 4;

    std::array<int, 4> grade_thresholds;
    grade_thresholds[0] = failing_score + 1;
    grade_thresholds[1] = failing_score + 1 + spacer;
    grade_thresholds[2] = failing_score + 1 + spacer + spacer;
    grade_thresholds[3] = failing_score + 1 + spacer + spacer + spacer;
        
    return grade_thresholds;
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(
    std::vector<int> student_scores, std::vector<std::string> student_names) {

    std::vector<std::string> rank;
    std::ostringstream oss;
    for (unsigned i = 0; i < student_scores.size(); i++) {
        oss.str("");
        oss.clear();
        oss << i + 1 << ". " << student_names[i] << ": " << student_scores[i];
        rank.emplace_back(oss.str());
    }

    return rank;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(std::vector<int> student_scores,
                          std::vector<std::string> student_names) {
    for (unsigned i = 0; i < student_scores.size(); i++) {
        if (student_scores.at(i) == 100) {
            return student_names.at(i);
        }
    }
    
    return "";
}
