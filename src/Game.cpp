#include "Game.h"
#include "Enemy.h"
#include "Weapon.h"
#include "raylib.h"
#include "raymath.h"
#include <iostream>
#include <random>
#include <time.h>

static int checkTowerCollision(const Tower &tower,
                               std::vector<Enemy> &enemies) {

  int dp = 0;
  for (auto &enemy : enemies) {
    if (CheckCollisionCircles(tower.pos, tower.towerRadius, enemy.getPosition(),
                              enemy.getCollisionRadius())) {
      dp = enemy.getHp();
      enemy.hit(dp);
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

  for (auto &enemy : enemies) {
    enemy.updatePosition();
  }

  for (auto it1 = enemies.begin(); it1 != enemies.end(); it1++) {
    for (auto it2 = bullets.begin(); it2 != bullets.end();) {
      if (CheckCollisionCircles(it1->getPosition(), it1->getCollisionRadius(),
                                it2->pos, it2->radius)) {
        it1->hit(it2->dp);
        bullets.erase(it2);
      } else
        it2++;
    }
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

  for (auto &bullet : bullets) {
    bullet.updatePos();
  }

  weapon.update();
  int nearest =
      findNearestEnemyInsideVision(tower, enemies, tower.visionRadius);
  if (nearest >= 0 && weapon.isBulletReady()) {
    bullets.push_back(weapon.getBullet(enemies[nearest].getPosition()));
  }

  frameCounter++;
}
