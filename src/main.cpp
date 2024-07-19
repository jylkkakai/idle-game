#include <iostream>
#include <raylib.h>

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

void UpdateDrawFrame(void);

int main(void) {

  std::cout << "Hello, World!" << std::endl;

  InitWindow(screenWidth, screenHeight, "Idle Game");
  SetTargetFPS(60);
  while (!WindowShouldClose()) {

    UpdateDrawFrame();
  }

  return 0;
}

void UpdateDrawFrame(void) {

  BeginDrawing();

  ClearBackground(RAYWHITE);

  DrawText("Idle Game", 290, 20, 20, GRAY);
  DrawRectangleV(gameArenaLoc, gameArenaSize, BLACK);
  DrawRectangleLinesEx(arenaEdgeLine, 2.0f, GRAY);

  BeginMode2D(camera);
  DrawCircleLines(0, 0, 100, LIGHTGRAY);
  DrawCircleLines(2900, 2900, 100, LIGHTGRAY);
  DrawCircleLines(-2900, 2900, 100, LIGHTGRAY);
  DrawCircleLines(2900, -2900, 100, LIGHTGRAY);
  DrawCircleLines(-2900, -2900, 100, LIGHTGRAY);

  DrawRing({0, 0}, 990, 1010, 0, 360, 1, DARKGRAY);
  EndMode2D();
  EndDrawing();
}
