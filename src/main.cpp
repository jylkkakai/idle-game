#include <iostream>
#include <raylib.h>

const int screenWidth = 1000;
const int screenHeight = 700;
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

  Vector2 gameArenaLoc = {50, 50};
  Vector2 gameArenaSize = {600, 600};
  Camera2D camera = {{350, 350}, {0, 0}, 0.0f, 1.0f};

  BeginDrawing();

  ClearBackground(RAYWHITE);

  DrawText("Idle Game", 250, 20, 20, GRAY);
  DrawRectangleV(gameArenaLoc, gameArenaSize, BLACK);
  DrawRectangleLinesEx({50, 50, 600, 600}, 2.0f, GRAY);
  BeginMode2D(camera);
  DrawCircleLines(0, 0, 10, LIGHTGRAY);
  // DrawCircleLines(0, 0, 200, DARKGRAY);
  DrawRing({0, 0}, 99, 101, 0, 360, 1, DARKGRAY);
  EndMode2D();
  EndDrawing();
}
