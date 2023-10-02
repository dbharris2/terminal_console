#include "board.h"

#include <iostream>
#include <string>
#include <windows.h>

#define CSI "\x1b["
#define DEFAULT_ATTRIBUTES "\x1b[ 0m"

Board::Board(int width, int height)
{
  _prevBoard.resize(height, std::vector<BoardPiece>(width, {' ', 0}));
  clear();
}

void Board::clear()
{
  _board.clear();
  _board.resize(_prevBoard.size(), std::vector<BoardPiece>(_prevBoard[0].size(), {' ', 0}));
  for (int row = 0; row < _board.size(); row++)
  {
    for (int col = 0; col < _board[0].size(); col++)
    {
      bool isTop = row == 0;
      bool isBottom = row == _board.size() - 1;
      bool isLeft = col == 0;
      bool isRight = col == _board[row].size() - 1;
      if (isTop || isBottom || isLeft || isRight)
      {
        _board[row][col].ch = 'x';
        _board[row][col].color = 32;
      }
    }
  }
}

int Board::height()
{
  return _board.size() - 2;
}

bool Board::isOutOfBounds(int row, int col)
{
  if (row <= 0 || col <= 0)
    return true;
  else if (row >= _board.size() - 1)
    return true;
  else if (col >= _board[0].size() - 1)
    return true;
  return false;
}

void Board::setItem(int row, int col, char c, int color)
{
  _board[row][col].ch = c;
  _board[row][col].color = color;
}

void Board::render()
{
  for (int row = 0; row < _board.size(); row++)
  {
    for (int col = 0; col < _board[0].size(); col++)
    {
      auto bp = _board[row][col];
      auto prevBp = _prevBoard[row][col];
      if (row == 10 && col == 10)
      {
        bp.ch = bp.ch;
      }
      if (bp == prevBp)
        continue;
      _printBoardPiece(bp, row, col);
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
  _prevBoard = _board;
}

int Board::width()
{
  return _board[0].size() - 2;
}

void Board::_printBoardPiece(BoardPiece bp, int row, int col)
{
  static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
  std::cout.flush();
  COORD coord = {(SHORT)col, (SHORT)row};
  SetConsoleCursorPosition(hOut, coord);
  std::cout << CSI << std::to_string(bp.color) + "m"
            << bp.ch << DEFAULT_ATTRIBUTES;
}
