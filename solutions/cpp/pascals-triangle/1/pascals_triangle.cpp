#include "pascals_triangle.h"

namespace pascals_triangle {

std::vector<std::vector<int>> generate_rows(int rows){
    std::vector<std::vector<int>> triangle{};

    if(rows == 0) return triangle;

    triangle.resize(rows);
    for(auto i = 0; i < rows; ++i) {
        for(auto j=0; j<=i; ++j){
            if(j==0 || j==i) triangle[i].emplace_back(1);
            else triangle[i].emplace_back(triangle[i-1][j-1] + triangle[i-1][j]);
        }
    }

    return triangle;
}

}  // namespace pascals_triangle
