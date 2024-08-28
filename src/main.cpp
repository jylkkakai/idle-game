#include "Enemy.h"
#include "Game.h"
#include <cstring>
#include <iostream>
#include <raylib.h>
#include <raymath.h>
#include <string>

const int screenWidth = 1000;
const int screenHeight = 700;
const int arenaWidth = 600;
const int arenaHeight = 600;
const int topPadding = 50;
const int leftPadding = 50;

const Vector2 gameArenaLoc = {leftPadding, topPadding};
const Vector2 gameArenaSize = {arenaWidth, arenaHeight};
const Rectangle arenaEdgeLine = {leftPadding, topPadding, arenaWidth,
                                 arenaHeight};
const Camera2D camera = {
    {int(arenaWidth / 2) + leftPadding, int(arenaHeight / 2) + topPadding},
    {0, 0},
    0.0f,
    0.1f};

void UpdateDrawFrame(Game *game);

int main() {
  // std::srand(time(NULL));

  Game game;
  game.init();
  // Enemy *common = new Enemy(EnemyType::COMMON);
  InitWindow(screenWidth, screenHeight, "Idle Game");
  SetTargetFPS(60);
  while (!WindowShouldClose()) {

    UpdateDrawFrame(&game);
    game.update();
  }

  return 0;
}

void UpdateDrawFrame(Game *game) {

  // std::cout << game->enemies.size() << std::endl;
  BeginDrawing();

  ClearBackground(RAYWHITE);

  DrawText("Idle Game", 290, 20, 20, GRAY);
  DrawRectangleV(gameArenaLoc, gameArenaSize, BLACK);
  DrawRectangleLinesEx(arenaEdgeLine, 2.0f, GRAY);

  BeginMode2D(camera);

  // Tower
  DrawCircleLines(game->tower.pos.x, game->tower.pos.y, game->tower.towerRadius,
                  game->tower.towerColor);

  DrawRing({game->tower.pos.x, game->tower.pos.y},
           game->tower.visionRadius - 10, game->tower.visionRadius + 10, 0, 360,
           1, game->tower.visionRadiusColor);

  // Enemies
  for (auto enemy : game->enemies) {
    enemy.render();
  }

  // Bullets
  for (auto bullet : game->bullets) {
    DrawCircleV(bullet.pos, bullet.radius, bullet.color);
  }

  DrawText(std::to_string(game->tower.hp).c_str(), 2000, -2900, 300, WHITE);
  DrawText(std::to_string(game->cash).c_str(), -2900, -2900, 300, WHITE);

  EndMode2D();
  EndDrawing();
}
