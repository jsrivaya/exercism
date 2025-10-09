#pragma once
#include<utility>

namespace queen_attack {

class chess_board {
  public:
    chess_board(const std::pair<int,int>&, const std::pair<int,int>&);
    std::pair<int,int> white() const;
    std::pair<int,int> black() const;
    bool can_attack() const;

  private:
    std::pair<int, int> queen_w;
    std::pair<int, int> queen_b;

    bool match_row() const;
    bool match_colum() const;
    bool match_diagonal() const;
};

}  // namespace queen_attack
