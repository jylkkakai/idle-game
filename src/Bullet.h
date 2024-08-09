#ifndef BULLET_H
#define BULLET_H
#include <raylib.h>

struct Bullet {
  int dp;
  Vector2 pos;
  Vector2 dir;
  float speed;
  Color color;

  void updatePos();
};

#endif // !BULLET_H
