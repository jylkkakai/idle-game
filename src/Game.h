#ifndef GAME_H
#define GAME_H
#include "Enemy.h"
#include "Tower.h"
#include "Weapon.h"
#include <vector>

struct Game {

  int cash = 0;
  Tower tower;
  std::vector<Enemy> enemies;
  WeaponClickable weapon;
  std::vector<Bullet> bullets;

  void init();
  void update();
};
#endif // !GAME_H
