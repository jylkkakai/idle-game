#include "Enemy.h"
#include "raylib.h"
#include <cassert>
#include <iostream>
#include <raymath.h>

Enemy::Enemy(EnemyType type, int level) : m_type(type) {

  switch (type) {
  case EnemyType::COMMON:
    m_type = EnemyType::COMMON;
    m_size.x = ENEMY_SIZE_X_COMMON;
    m_size.y = ENEMY_SIZE_Y_COMMON;
    m_collisionRadius = float(ENEMY_SIZE_Y_COMMON) / 2;
    m_speed = 5.0f;
    m_framesToRemove = 10;
    m_color = YELLOW;
    m_maxHp = 10.0 * pow(1.1, level - 1);
    m_hp = m_maxHp;
    m_drop = 12.0 * pow(1.2, level - 1);
    break;
  default:
    assert(!"Unreachable!");
    break;
  }
  // std::cout << m_drop << std::endl;

  int randVal = (rand() % (6000 - ENEMY_SIZE_X_COMMON));
  int side = randVal % 4;

  randVal = randVal + ENEMY_SIZE_X_COMMON / 2 - 3000;
  switch (side) {
  case 0: // top
    m_pos.x = randVal;
    m_pos.y = -3000 + ENEMY_SIZE_Y_COMMON;
    break;
  case 1: // right
    m_pos.x = 3000 - ENEMY_SIZE_X_COMMON;
    m_pos.y = randVal;
    break;
  case 2: // bottom
    m_pos.x = randVal;
    m_pos.y = 3000 - ENEMY_SIZE_Y_COMMON;
    break;
  case 3: // left
    m_pos.x = -3000 + ENEMY_SIZE_X_COMMON;
    m_pos.y = randVal;
    break;
  default:
    assert(!"Unreachable!");
    break;
  }
}

void Enemy::updatePosition() {

  if (m_type != EnemyType::DESTROYED) {
    m_pos = Vector2MoveTowards(
        m_pos, {0 - m_collisionRadius, 0 - m_collisionRadius}, m_speed);
  } else {
    if (m_framesToRemove <= 0) {
      m_type = EnemyType::REMOVABLE;
    }
    m_framesToRemove--;
  }
}

void Enemy::hit(int hp) {
  m_hp -= hp;
  if (m_hp <= 0 && (m_type != EnemyType::REMOVABLE)) {
    m_type = EnemyType::DESTROYED;
    m_hp = 0.0;
  }
}

void Enemy::render() {

  Vector2 renderSize{m_size.x * m_hp / m_maxHp, m_size.y * m_hp / m_maxHp};
  Vector2 renderPos{m_pos.x - renderSize.x / 2, m_pos.y - renderSize.y / 2};
  float lineThickness = 5.0;

  if (m_type != EnemyType::DESTROYED) {
    DrawRectangleLinesEx(
        {m_pos.x - m_size.x / 2, m_pos.y - m_size.y / 2, m_size.x, m_size.y},
        lineThickness, m_color);
    DrawRectangleV(renderPos, renderSize, m_color);
  } else {
    DrawRectangleLinesEx({renderPos.x, renderPos.y, renderSize.x, renderSize.y},
                         lineThickness, m_color);
  }
}

float Enemy::getDrop() {
  float drop = m_drop;
  m_drop = 0.0;
  return drop;
}

Vector2 Enemy::getPosition() { return m_pos; }
int Enemy::getHp() { return m_hp; }
Vector2 Enemy::getSize() { return m_size; }
float Enemy::getCollisionRadius() { return m_collisionRadius; }
float Enemy::getSpeed() { return m_speed; }
Color Enemy::getColor() { return m_color; }
EnemyType Enemy::getType() { return m_type; }
