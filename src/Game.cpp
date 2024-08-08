#include "Game.h"
#include "Enemy.h"
#include "raylib.h"
#include <iostream>
#include <random>
#include <time.h>

void Game::init() {

  std::srand(time(NULL));

  tower.hp = 50;
  tower.pos = {0, 0};
  tower.towerRadius = 100.0;
  tower.towerColor = LIGHTGRAY;
  tower.visionRadius = 1000.0;
  tower.visionRadiusColor = DARKGRAY;
}

static void checkTowerCollision(Tower &tower, std::vector<Enemy> &enemies) {

  for (auto it = enemies.begin(); it != enemies.end(); it++) {
    if (CheckCollisionCircles(tower.pos, tower.towerRadius,
                              it->getCollisionPosition(),
                              it->getCollisionRadius())) {
      // enemies.erase(it);
      it->setType(EnemyType::DESTROYED);
    }
  }
}

void Game::update() {

  static int frameCounter = 0;
  static int frameCounterMax = 30;
  // static int framesToRemove = 10;
  static int enNum = 0;
  static int maxEnemies = 1;
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
  checkTowerCollision(tower, enemies);

  for (auto it = enemies.begin(); it != enemies.end();) {
    if (it->getType() == EnemyType::REMOVABLE) {
      std::cout << "Remove" << std::endl;
      enemies.erase(it);
      // it->setType(EnemyType::DESTROYED);
    } else {
      // if (framesToRemove <= 0) {
      //   it->setType(EnemyType::REMOVABLE);
      // } else if (it->getType() == EnemyType::DESTROYED) {
      //   framesToRemove--;
      // }
      it++;
    }
  }
  frameCounter++;
}
