#pragma once

#include <memory>

#include "boardgame.h"
#include "dmvec.h"
#include "snake.h"

class Board;

class SnakeGame : public IBoardGame
{
public:
  SnakeGame(std::shared_ptr<Board> board, std::unique_ptr<Snake> snake);
  bool isOver();
  virtual void render();
  void setIsOver(bool isOver);
  void update(int direction);

private:
  std::shared_ptr<Board> _board;
  DMVec _fruit;
  bool _isOver = false;
  std::unique_ptr<Snake> _snake;

  DMVec _randomBoardItem();
};