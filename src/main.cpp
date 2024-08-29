#include "Enemy.h"
#include "Game.h"
#include <cstring>
#include <iostream>
#include <raylib.h>
#include <raymath.h>
#include <string>

void UpdateDrawFrame(Game::Game *game);

int main() {

  std::srand(time(NULL));

  Game::Game game;
  InitWindow(Game::screenWidth, Game::screenHeight, "Idle Game");
  SetTargetFPS(60);
  while (!WindowShouldClose()) {

    UpdateDrawFrame(&game);
    game.update();
  }

  return 0;
}

void UpdateDrawFrame(Game::Game *game) {

  BeginDrawing();

  ClearBackground(RAYWHITE);

  DrawText("Idle Game", 290, 20, 20, GRAY);
  DrawRectangleV(Game::gameArenaLoc, Game::gameArenaSize, BLACK);
  DrawRectangleLinesEx(Game::arenaEdgeLine, 2.0f, GRAY);

  BeginMode2D(Game::camera);

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

  DrawText(std::to_string(int(game->tower.hp)).c_str(),
           Game::gameArenaXMax - 500, Game::gameArenaYMin + 100, 300, WHITE);
  DrawText(std::to_string(game->cash).c_str(), Game::gameArenaXMin + 100,
           Game::gameArenaYMin + 100, 300, WHITE);
  DrawText(("Level " + std::to_string(game->currentLevel)).c_str(), -500,
           Game::gameArenaYMin + 100, 300, WHITE);

  EndMode2D();
  EndDrawing();
}
