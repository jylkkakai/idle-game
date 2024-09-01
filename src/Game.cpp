#include "Game.h"
#include "Enemy.h"
#include "Weapon.h"
#include "raylib.h"
#include "raymath.h"
#include <iostream>
// #include <random>
// #include <time.h>

static float checkTowerCollision(const Tower &tower,
                                 std::vector<Enemy> &enemies) {

  float dp = 0;
  for (auto &enemy : enemies) {
    if (enemy.getType() != EnemyType::DESTROYED &&
        CheckCollisionCircles(tower.pos, tower.towerRadius, enemy.getPosition(),
                              enemy.getCollisionRadius())) {
      dp = enemy.getHp();
      enemy.hit(dp + 1.0);
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

void Game::Game::update() {

  static int frameCounter = 0;
  static int frameCounterMax = 30;
  // static int enNum = 0;
  // static int maxEnemies = 10;

  // New enemies
  if (frameCounter >= frameCounterMax && numOfEnemies < maxEnemies) {
    Enemy enemy(EnemyType::COMMON, currentLevel);
    enemies.push_back(enemy);
    numOfEnemies++;
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
        it2 = bullets.erase(it2);
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
        float drop = it->getDrop();
        cash += drop;
      }
      it++;
    }
  }

  for (auto &bullet : bullets) {
    bullet.updatePos();
  }
  for (auto it = bullets.begin(); it != bullets.end();) {
    if (it->pos.x < gameArenaXMin + 10 || it->pos.x > gameArenaXMax - 10 ||
        it->pos.y < gameArenaYMin + 10 || it->pos.y > gameArenaYMax - 10) {
      it = bullets.erase(it);
    } else
      it++;
  }

  weapon.update();
  weaponAuto.update();

  if (cash >= weapon.getWeaponUpdateCost() && weapon.isButtonHovered() &&
      IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
    cash -= weapon.getWeaponUpdateCost();
    weapon.buyWeaponUpdate();
  }
  if (cash >= weaponAuto.getWeaponUpdateCost() &&
      weaponAuto.isButtonHovered() && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
    cash -= weaponAuto.getWeaponUpdateCost();
    weaponAuto.buyWeaponUpdate();
  }

  int nearest =
      findNearestEnemyInsideVision(tower, enemies, tower.visionRadius);
  if (nearest >= 0 && weapon.isBulletReady()) {
    bullets.push_back(weapon.getBullet(enemies[nearest].getPosition()));
  }
  if (nearest >= 0 && weaponAuto.isBulletReady()) {
    bullets.push_back(weaponAuto.getBullet(enemies[nearest].getPosition()));
  }

  if (tower.hp <= 0 || (numOfEnemies == maxEnemies && enemies.empty())) {
    resetLevel();
    frameCounter = 0;
    frameCounterMax = rand() % 100 + 30;
  }
  frameCounter++;
}

void Game::Game::resetLevel() {
  if (numOfEnemies == maxEnemies && enemies.empty() &&
      currentLevel > passedLevel) {
    passedLevel = currentLevel;
    currentLevel++;
    cash += currentLevel * 50;
  }
  tower.hp = 50;
  numOfEnemies = 0;
  enemies.clear();
  bullets.clear();
}
