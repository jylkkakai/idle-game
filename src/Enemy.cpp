#include "Enemy.h"
// #include "Game.h"
#include "raylib.h"
#include <cassert>
// #include <chrono>
#include <iostream>
// #include <random>
#include <raymath.h>
// #include <time.h>

Enemy::Enemy(EnemyType type) : m_type(type) {

  switch (type) {
  case EnemyType::COMMON:
    m_type = EnemyType::COMMON;
    m_size.x = ENEMY_SIZE_X_COMMON;
    m_size.y = ENEMY_SIZE_Y_COMMON;
    m_collisionRadius = float(ENEMY_SIZE_Y_COMMON) / 2;
    m_speed = 5.0f;
    m_framesToRemove = 10;
    m_color = YELLOW;
    m_hp = 10;
    m_drop = 2;
    break;
  default:
    assert(!"Unreachable!");
    break;
  }

  int randVal = rand() % (6000 - ENEMY_SIZE_X_COMMON);
  int side = randVal % 4;

  switch (side) {
  case 0: // top
    m_pos.x = randVal - 3000;
    m_pos.y = -3000;
    break;
  case 1: // right
    m_pos.x = 3000 - ENEMY_SIZE_X_COMMON;
    m_pos.y = randVal - 3000;
    break;
  case 2: // bottom
    m_pos.x = randVal - 3000;
    m_pos.y = 3000 - ENEMY_SIZE_Y_COMMON;
    break;
  case 3: // left
    m_pos.x = -3000;
    m_pos.y = randVal - 3000;
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

Vector2 Enemy::getCollisionPosition() {
  return {m_pos.x + m_collisionRadius, m_pos.y + m_collisionRadius};
}

void Enemy::hit(int hp) {
  m_hp -= hp;
  if (m_hp <= 0 && (m_type != EnemyType::REMOVABLE))
    m_type = EnemyType::DESTROYED;
}

int Enemy::getDrop() {
  int drop = m_drop;
  m_drop = 0;
  return drop;
}

Vector2 Enemy::getPosition() { return m_pos; }
int Enemy::getHp() { return m_hp; }
Vector2 Enemy::getSize() { return m_size; }
float Enemy::getCollisionRadius() { return m_collisionRadius; }
float Enemy::getSpeed() { return m_speed; }
Color Enemy::getColor() { return m_color; }
EnemyType Enemy::getType() { return m_type; }
// void Enemy::setType(EnemyType type) { m_type = type; }
