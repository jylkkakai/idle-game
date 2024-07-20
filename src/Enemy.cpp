#include "Enemy.h"
#include "Game.h"
#include "raylib.h"
#include <cassert>
// #include <iostream>
#include <random>
#include <raymath.h>
#include <time.h>

Enemy::Enemy(EnemyType type) : m_type(type) {

  switch (type) {
  case COMMON:
    m_type = COMMON;
    m_size.x = ENEMY_SIZE_X_COMMON;
    m_size.y = ENEMY_SIZE_Y_COMMON;
    m_speed = 5.0f;
    m_color = YELLOW;
    break;
  default:
    assert(!"Unreachable!");
    break;
  }

  std::srand(time(NULL));
  std::minstd_rand0 gen(time(NULL));
  std::uniform_int_distribution<int> dist(0, 6000 - ENEMY_SIZE_X_COMMON);
  int randVal = std::rand() % (6000 - ENEMY_SIZE_X_COMMON);
  int side = randVal % 4;
  side = randVal % 4;

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

  m_pos = Vector2MoveTowards(m_pos, {0 - 50, 0 - 50}, m_speed);
}
Vector2 Enemy::getPosition() { return m_pos; }
Vector2 Enemy::getSize() { return m_size; }
float Enemy::getSpeed() { return m_speed; }
Color Enemy::getColor() { return m_color; }
