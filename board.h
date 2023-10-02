#pragma once

#include <vector>

typedef struct BoardPiece
{
  char ch;
  int color;

  bool operator==(const BoardPiece &v2) const
  {
    const BoardPiece &v1 = (*this);
    return v1.ch == v2.ch && v1.color == v2.color;
  }
} BoardPiece;

class Board
{
public:
  Board(int width, int height);
  void clear();
  int height();
  bool isOutOfBounds(int row, int col);
  void setItem(int row, int col, char c, int color = 0);
  void render();
  int width();

private:
  std::vector<std::vector<BoardPiece>> _board;
  std::vector<std::vector<BoardPiece>> _prevBoard;

  void Board::_printBoardPiece(BoardPiece bp, int row, int col);
};