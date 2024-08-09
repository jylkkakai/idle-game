#ifndef ENEMY_H
#define ENEMY_H
#include "raylib.h"

const int ENEMY_SIZE_X_COMMON = 100;
const int ENEMY_SIZE_Y_COMMON = 100;
enum class EnemyType { COMMON, FAST, HUGE, DESTROYED, REMOVABLE };

class Enemy {
public:
  Enemy(EnemyType type);

  void updatePosition();
  int getHp();
  Vector2 getPosition();
  Vector2 getSize();
  Vector2 getCollisionPosition();
  float getCollisionRadius();
  float getSpeed();
  Color getColor();
  void hit(int hp);
  int getDrop();
  EnemyType getType();

private:
  EnemyType m_type;
  int m_hp;
  Vector2 m_pos;
  Vector2 m_size;
  float m_collisionRadius;
  float m_speed;
  Color m_color;
  int m_drop;
  int m_framesToRemove;
};
#endif // !ENEMY_H
