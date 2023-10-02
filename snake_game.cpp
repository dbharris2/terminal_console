#include "snake_game.h"

#include <iostream>
#include <windows.h>

#include "board.h"
#include "dmvec.h"
#include "snake.h"

SnakeGame::SnakeGame(std::shared_ptr<Board> board, std::unique_ptr<Snake> snake)
{
  _board = board;
  _fruit = _randomBoardItem();
  _isOver = false;
  _snake = std::move(snake);
}

bool SnakeGame::isOver()
{
  return _isOver;
}

void SnakeGame::render()
{
  auto head = _snake->head();
  if (_board->isOutOfBounds(head.y, head.x))
  {
    _isOver = true;
  }

  _board->setItem(_fruit.y, _fruit.x, '*', 31);
  auto weakBoard = std::weak_ptr<Board>(_board);
  _snake->forEach([&weakBoard](DMVec pos) -> void
                  { 
                    auto strongBoard = weakBoard.lock();
                    strongBoard->setItem(pos.y, pos.x, 'o', 35); });
  _board->setItem(head.y, head.x, 's', 35);

  _board->render();
}

void SnakeGame::setIsOver(bool isOver)
{
  _isOver = isOver;
}

void SnakeGame::update(int direction)
{
  _board->clear();

  auto head = _snake->head();
  if (head == _fruit)
  {
    _snake->eat();
    _fruit = _randomBoardItem();
  }
  _snake->move(direction);
}

DMVec SnakeGame::_randomBoardItem()
{
  auto x = rand() % _board->width() + 1;
  auto y = rand() % _board->height() + 1;
  return {x, y};
}
