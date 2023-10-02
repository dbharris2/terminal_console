#include "board.h"

#include <iostream>
#include <string>
#include <windows.h>

#define CSI "\x1b["
#define DEFAULT_ATTRIBUTES "\x1b[ 0m"

Board::Board(int width, int height)
{
  _emptyBoard.resize(height, std::vector<BoardPiece>(width, {' ', 0}));
  for (int row = 0; row < _emptyBoard.size(); row++)
  {
    for (int col = 0; col < _emptyBoard[0].size(); col++)
    {
      bool isTop = row == 0;
      bool isBottom = row == _emptyBoard.size() - 1;
      bool isLeft = col == 0;
      bool isRight = col == _emptyBoard[row].size() - 1;
      if (isTop || isBottom || isLeft || isRight)
      {
        _emptyBoard[row][col].ch = 'x';
        _emptyBoard[row][col].color = 32;
      }
    }
    clear();
  }
}

void Board::clear()
{
  _board = _emptyBoard;
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
  // system("cls"); // Clear the console
  std::cout << CSI << "1;1H";
  std::cout << CSI << "2J";

  for (auto row : _board)
  {
    for (auto piece : row)
    {
      _printBoardPiece(piece);
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

int Board::width()
{
  return _board[0].size() - 2;
}

void Board::_printBoardPiece(BoardPiece bp)
{
  // Without color - fast
  // std::cout << bp.ch;

  // With color - slow
  std::cout << CSI << std::to_string(bp.color) + "m"
            << bp.ch << DEFAULT_ATTRIBUTES;
}
