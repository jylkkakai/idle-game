#ifndef ENEMY_H
#define ENEMY_H
#include "Game.h"
#include "raylib.h"

class Enemy {
public:
  Enemy(EnemyType type);
  Enemy(Enemy &&) = default;
  Enemy(const Enemy &) = default;
  Enemy &operator=(Enemy &&) = default;
  Enemy &operator=(const Enemy &) = default;
  ~Enemy() = default;

  void updatePosition();
  Vector2 getPosition();
  Vector2 getSize();
  float getSpeed();
  Color getColor();

private:
  EnemyType m_type;
  Vector2 m_pos;
  Vector2 m_size;
  float m_speed;
  Color m_color;
};
#endif // !ENEMY_H
