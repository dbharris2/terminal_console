#include "snake.h"

Snake::Snake(int x, int y)
{
  _position.resize(1, {x, y});
}

void Snake::eat()
{
  auto h = head();
  _position.push_back({h.x, h.y});
}

void Snake::forEach(std::function<void(DMVec)> func)
{
  for (const auto pos : _position)
  {
    func(pos);
  }
}

DMVec Snake::head()
{
  return _position.back();
}

void Snake::move(int direction)
{
  auto h = head();
  if (direction == 1)
  {
    _position.pop_front();
    _position.push_back({h.x, h.y - 1});
  }
  else if (direction == 2)
  {
    _position.pop_front();
    _position.push_back({h.x, h.y + 1});
  }
  else if (direction == 3)
  {
    _position.pop_front();
    _position.push_back({h.x - 1, h.y});
  }
  else if (direction == 4)
  {
    _position.pop_front();
    _position.push_back({h.x + 1, h.y});
  }
}
