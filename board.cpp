#include "board.h"

#include <iostream>
#include <windows.h>

Board::Board(int width, int height)
{
  _board.resize(height, std::vector<char>(width, ' '));
  _emptyBoard.resize(height, std::vector<char>(width, ' '));
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

void Board::setItem(int row, int col, char c)
{
  _board[row][col] = c;
}

void Board::render()
{
  system("cls"); // Clear the console

  for (int row = 0; row < _board.size(); row++)
  {
    for (int col = 0; col < _board[0].size(); col++)
    {
      if (row == 0)
        std::cout << "x";
      else if (row == _board.size() - 1)
        std::cout << "x";
      else if (col == 0)
        std::cout << "x";
      else if (col == _board[row].size() - 1)
        std::cout << "x";
      else
        std::cout << _board[row][col];
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

int Board::width()
{
  return _board[0].size() - 2;
}
