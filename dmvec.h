#pragma once

typedef struct DMVec
{
  int x;
  int y;

  bool operator==(const DMVec &v2) const
  {
    const DMVec &v1 = (*this);
    return v1.x == v2.x && v1.y == v2.y;
  }
} DMVec;
