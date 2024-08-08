#include "Game.h"
#include "Enemy.h"
#include <random>
#include <time.h>

Game::Game() {

  std::srand(time(NULL));
  m_frameCounter = 0;
}

void Game::update() {

  static int frameCounter = 0;
  static int frameCounterMax = 30;
  static int enNum = 0;
  static int maxEnemies = 10;
  if (frameCounter == frameCounterMax && enNum < maxEnemies) {

    Enemy enemy(EnemyType::COMMON);
    enemies.push_back(enemy);
    enNum++;
    frameCounter = 0;
    frameCounterMax = rand() % 100 + 30;
  }
  frameCounter++;
}
