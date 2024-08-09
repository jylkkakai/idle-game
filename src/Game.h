#ifndef GAME_H
#define GAME_H
#include "Enemy.h"
#include "Tower.h"
// #include <cstddef>
#include <vector>
// #include "Tower.h"

struct Game {

  int cash;
  Tower tower;
  std::vector<Enemy> enemies;
  // bullets;

  void init();
  void update();
};
#endif // !GAME_H
