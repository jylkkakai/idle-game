#ifndef GAME_H
#define GAME_H
#include "Enemy.h"
#include "Tower.h"
#include "Weapon.h"
#include <vector>

namespace Game {

constexpr int screenWidth = 1000;
constexpr int screenHeight = 700;
constexpr int screenArenaWidth = 600;
constexpr int screenArenaHeight = 600;
constexpr int topPadding = 50;
constexpr int leftPadding = 50;
constexpr float arenaZoom = 0.1f;

constexpr Vector2 gameArenaLoc = {leftPadding, topPadding};
constexpr Vector2 gameArenaSize = {screenArenaWidth, screenArenaHeight};
constexpr Rectangle arenaEdgeLine = {leftPadding, topPadding, screenArenaWidth,
                                     screenArenaHeight};
constexpr Camera2D camera = {{int(screenArenaWidth / 2) + leftPadding,
                              int(screenArenaHeight / 2) + topPadding},
                             {0, 0},
                             0.0f,
                             arenaZoom};

constexpr int gameArenaWidth = screenArenaWidth / arenaZoom;
constexpr int gameArenaHeight = screenArenaHeight / arenaZoom;
constexpr int gameArenaXMin = -gameArenaWidth + gameArenaWidth / 2;
constexpr int gameArenaXMax = gameArenaWidth - gameArenaWidth / 2;
constexpr int gameArenaYMin = -gameArenaHeight + gameArenaHeight / 2;
constexpr int gameArenaYMax = gameArenaHeight - gameArenaHeight / 2;

struct Game {

  int cash = 0;
  int currentLevel = 1;
  int passedLevel = 0;
  int maxEnemies = 10;
  int numOfEnemies = 0;
  Tower tower;
  std::vector<Enemy> enemies;
  WeaponClickable weapon;
  std::vector<Bullet> bullets;

  void init();
  void update();
  void resetLevel();
};

} // namespace Game
#endif // !GAME_H
