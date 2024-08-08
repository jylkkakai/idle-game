#include "Enemy.h"
#include "Game.h"
#include <iostream>
#include <raylib.h>
#include <raymath.h>

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
  DrawCircleLines(game->tower.pos.x, game->tower.pos.y, game->tower.towerRadius,
                  game->tower.towerColor);

  DrawRing({game->tower.pos.x, game->tower.pos.y},
           game->tower.visionRadius - 10, game->tower.visionRadius + 10, 0, 360,
           1, game->tower.visionRadiusColor);

  for (auto i = 0; i < game->enemies.size(); i++) {
    if (game->enemies[i].getType() != EnemyType::DESTROYED) {
      DrawRectangleV(game->enemies[i].getPosition(), game->enemies[i].getSize(),
                     game->enemies[i].getColor());
    } else {
      DrawRectangleLinesEx(
          {game->enemies[i].getPosition().x, game->enemies[i].getPosition().y,
           game->enemies[i].getSize().x, game->enemies[i].getSize().y},
          10.0, game->enemies[i].getColor());
    }
    // game->enemies[i].updatePosition();
  }
  // for (auto enemy : game->enemies) {
  //   DrawRectangleV(enemy.getPosition(), enemy.getSize(), enemy.getColor());
  //   enemy.updatePosition();
  // }

  // enemyPos = Vector2MoveTowards(enemyPos, {0 - 50, 0 - 50}, 5.0f);

  // DrawCircleLines(2900, 2900, 100, LIGHTGRAY);
  // DrawCircleLines(-2900, 2900, 100, LIGHTGRAY);
  // DrawCircleLines(2900, -2900, 100, LIGHTGRAY);
  // DrawCircleLines(-2900, -2900, 100, LIGHTGRAY);
  EndMode2D();
  EndDrawing();
}
