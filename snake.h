#pragma once

#include <functional>
#include <deque>

#include "dmvec.h"

class Snake
{
public:
  Snake(int x, int y);
  void eat();
  void forEach(std::function<void(DMVec)> func);
  DMVec head();
  void move(int direction);

private:
  std::deque<DMVec> _position;
};