#include "snake_game_factory.h"

#include <conio.h>
#include <iostream>
#include <windows.h>

#include "board.h"
#include "snake.h"
#include "snake_game.h"

SnakeGameFactory::SnakeGameFactory()
{
  auto board = std::make_shared<Board>(20, 20);
  auto snake = std::make_unique<Snake>(10, 10);
  _snakeGame = std::make_unique<SnakeGame>(board, std::move(snake));
  _snakeDirection = 1;
}

void SnakeGameFactory::run()
{
  while (!_snakeGame->isOver())
  {
    _snakeGame->render();
    int input = _UserInput();
    if (input == -1)
    {
      _snakeGame->setIsOver(true);
    }
    else if (input >= 1 && input <= 4)
    {
      _snakeDirection = input;
    }
    _snakeGame->update(_snakeDirection);
    Sleep(200);
  }
}

int _UserInput()
{
  if (_kbhit())
  {
    switch (_getch())
    {
    case 'a':
      return 3;
    case 'd':
      return 4;
    case 'w':
      return 1;
    case 's':
      return 2;
    case 'q':
      return -1;
    }
  }
  return 0;
}