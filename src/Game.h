#ifndef GAME_H
#define GAME_H
#include "Enemy.h"
#include "Tower.h"
#include "Weapon.h"
// #include <cstddef>
#include <vector>
// #include "Tower.h"

struct Game {

  int cash = 0;
  Tower tower;
  std::vector<Enemy> enemies;
  WeaponClickable weapon;
  // bullets;

  void init();
  void update();
};
#endif // !GAME_H
