#include "pascals_triangle.h"

namespace pascals_triangle {

std::vector<std::vector<int>> generate_rows(int rows){
    std::vector<std::vector<int>> triangle{};

    triangle.resize(rows);
    for(auto i = 0; i < rows; ++i) {
        triangle[i].resize(i + 1, 1);
        for(auto j=1; j<i; ++j){
            triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
        }
    }

    return triangle;
}

}  // namespace pascals_triangle
