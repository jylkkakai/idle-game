#ifndef ENEMY_H
#define ENEMY_H
#include "raylib.h"

const int ENEMY_SIZE_X_COMMON = 100;
const int ENEMY_SIZE_Y_COMMON = 100;
enum class EnemyType { COMMON, FAST, HUGE, DESTROYED, REMOVABLE };

class Enemy {
public:
  Enemy(EnemyType, int);

  void updatePosition();
  int getHp();
  Vector2 getPosition();
  Vector2 getSize();
  float getCollisionRadius();
  float getSpeed();
  Color getColor();
  void render();
  void hit(int hp);
  float getDrop();
  EnemyType getType();

private:
  EnemyType m_type;
  float m_maxHp;
  float m_hp;
  Vector2 m_pos;
  Vector2 m_size;
  float m_collisionRadius;
  float m_speed;
  Color m_color;
  float m_drop;
  int m_framesToRemove;
};
#endif // !ENEMY_H
