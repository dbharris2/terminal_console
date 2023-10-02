#pragma once

#include <vector>

class Board
{
public:
  Board(int width, int height);
  void clear();
  int height();
  bool isOutOfBounds(int row, int col);
  void setItem(int row, int col, char c);
  void render();
  int width();

private:
  std::vector<std::vector<char>> _board;
  std::vector<std::vector<char>> _emptyBoard;
};