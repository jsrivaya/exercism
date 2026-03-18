#include "spiral_matrix.h"

#include <iostream>

namespace spiral_matrix {

void fill_matrix(std::vector<std::vector<uint32_t>>& matrix, int32_t top, int32_t bottom, int32_t left, int32_t right, int32_t counter) {
    if (bottom < top || right < left) { // base case
        return;
    }

    if (bottom == top && left == right) {
        matrix[top][left] = counter;
        return;
    }
    // fill outer ring
    // top row: from left to right
    for (int col = left; col <= right; ++col) {
        matrix[top][col] = counter++;
    }
    // right column: from top to bottom
    for (int row = top+1; row <= bottom; ++row) {
        matrix[row][right] = counter++;
    }
    // bottom row: from right to left
    for (int col = right-1; col >= left; --col) {
        matrix[bottom][col] = counter++;
    }
    // left colum: from bottom to top
    for (int row = bottom-1; row > top; --row) {
        matrix[row][left] = counter++;
    }
    // fill inner ring
    fill_matrix(matrix, top+1, bottom-1, left+1, right-1, counter);
}
    
std::vector<std::vector<uint32_t>> spiral_matrix(uint32_t s) {
    auto result = std::vector<std::vector<uint32_t>>(s, std::vector<uint32_t>(s));
    fill_matrix(result, 0, s-1, 0, s-1, 1);
    
    return result;
};

}  // namespace spiral_matrix
