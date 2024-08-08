#ifndef GAME_H
#define GAME_H
#include "Enemy.h"
#include <cstddef>
#include <vector>
// #include "Tower.h"

class Game {
public:
  Game();
  ~Game();

  void update();

  // Tower m_tower;
  std::vector<Enemy> enemies;
  // m_bullets;

private:
  std::size_t m_frameCounter;
};
#endif // !GAME_H
