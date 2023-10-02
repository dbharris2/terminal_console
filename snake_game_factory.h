#include "snake_game.h"

class SnakeGameFactory
{
public:
  SnakeGameFactory();
  void run();

private:
  int _snakeDirection;
  std::unique_ptr<SnakeGame> _snakeGame;
};

int _UserInput();