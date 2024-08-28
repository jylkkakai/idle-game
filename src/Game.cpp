#include "Game.h"
#include "Enemy.h"
#include "Weapon.h"
#include "raylib.h"
#include "raymath.h"
#include <iostream>
#include <random>
#include <time.h>

void Game::init() {}

static int checkTowerCollision(const Tower &tower,
                               std::vector<Enemy> &enemies) {

  int dp = 0;
  for (auto it = enemies.begin(); it != enemies.end(); it++) {
    if (CheckCollisionCircles(tower.pos, tower.towerRadius,
                              it->getCollisionPosition(),
                              it->getCollisionRadius())) {
      dp = it->getHp();
      it->hit(dp);
    }
  }
  return dp;
}

static int findNearestEnemyInsideVision(const Tower &tower,
                                        std::vector<Enemy> &enemies,
                                        float maxDist) {

  float minDist = maxDist;
  int minIndex = -1;
  for (auto i = 0; i < enemies.size(); i++) {
    float tDist = Vector2Distance(enemies[i].getPosition(), tower.pos);
    if (tDist < minDist) {
      minDist = tDist;
      minIndex = i;
    }
  }
  return minIndex;
}

void Game::update() {

  static int frameCounter = 0;
  static int frameCounterMax = 30;
  static int enNum = 0;
  static int maxEnemies = 10;

  // New enemies
  if (frameCounter == frameCounterMax && enNum < maxEnemies) {
    Enemy enemy(EnemyType::COMMON);
    enemies.push_back(enemy);
    enNum++;
    frameCounter = 0;
    frameCounterMax = rand() % 100 + 30;
  }

  for (auto i = 0; i < enemies.size(); i++) {
    enemies[i].updatePosition();
  }

  tower.hp -= checkTowerCollision(tower, enemies);
  for (auto it = enemies.begin(); it != enemies.end();) {
    if (it->getType() == EnemyType::REMOVABLE) {
      enemies.erase(it);
    } else {
      if (it->getType() == EnemyType::DESTROYED) {
        cash += it->getDrop();
      }
      it++;
    }
  }

  for (auto i = 0; i < bullets.size(); i++) {
    bullets[i].updatePos();
  }

  weapon.update();
  int nearest =
      findNearestEnemyInsideVision(tower, enemies, tower.visionRadius);
  if (nearest >= 0 && weapon.isBulletReady()) {
    bullets.push_back(weapon.getBullet(enemies[nearest].getPosition()));
  }

  frameCounter++;
}
