#ifndef ENEMY_H
#define ENEMY_H
#include "raylib.h"

const int ENEMY_SIZE_X_COMMON = 100;
const int ENEMY_SIZE_Y_COMMON = 100;
enum class EnemyType { COMMON, FAST, HUGE, DESTROYED };

class Enemy {
public:
  Enemy(EnemyType type);

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
