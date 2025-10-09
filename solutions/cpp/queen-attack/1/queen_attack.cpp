#include "queen_attack.h"
#include <stdexcept>

namespace queen_attack {

bool in_range(const std::pair<int, int>& p, const std::pair<int, int>& r) {
    return (p.first >= r.first && p.first <= r.second) &&
            (p.second >= r.first && p.second <= r.second);
}
bool collision(const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
    return (p1.first == p2.first) && (p1.second == p2.second);
}

bool is_valid(const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
    return in_range(p1, {0,7}) &&
        in_range(p2, {0,7}) &&
        !collision(p1, p2);
}
chess_board::chess_board(const std::pair<int,int>& queen_w, const std::pair<int,int>& queen_b) : queen_w(queen_w), queen_b(queen_b) {
    if(!is_valid(queen_w, queen_b)) {
        throw std::domain_error("Invalid position");
    }
}
std::pair<int,int> chess_board::white() const {
    return queen_w;
}
std::pair<int,int> chess_board::black() const {
    return queen_b;
}
bool chess_board::can_attack() const {
    return match_row() || match_colum() || match_diagonal();
}
bool chess_board::match_row () const {
    return queen_w.first == queen_b.first;
}
bool chess_board::match_colum() const {
    return queen_w.second == queen_b.second;
}
bool chess_board::match_diagonal() const {
    return (queen_w.first + queen_w.second) == (queen_b.first + queen_b.second) ||
            (queen_w.first - queen_w.second) == (queen_b.first - queen_b.second);
}
}  // namespace queen_attack
