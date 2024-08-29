#include "Weapon.h"
#include "raylib.h"
#include <cstdlib>
// #include <cstring>
// #include "Tower.h"
#include <string>

bool WeaponClickable::isMouseOnArena() {

  Vector2 mousePos = GetMousePosition();
  return mousePos.x > 50 && mousePos.x < 650 && mousePos.y > 50 &&
         mousePos.y < 650;
}
bool WeaponClickable::isMouseOnButton() {

  Vector2 mousePos = GetMousePosition();
  return mousePos.x > 700 && mousePos.x < 950 && mousePos.y > 50 &&
         mousePos.y < 100;
}

void WeaponClickable::update() {
  m_isArenaHovered = isMouseOnArena();
  m_isButtonHovered = isMouseOnButton();

  if (m_isArenaHovered || m_isButtonHovered)
    SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
  else
    SetMouseCursor(MOUSE_CURSOR_ARROW);

  m_bulletReady = (m_isArenaHovered && IsMouseButtonPressed(MOUSE_BUTTON_LEFT));

  // Vector2 mousePos = GetMousePosition();
  // if (cash >= m_weaponUpdateCost && mousePos.x > 50 && mousePos.x < 650 &&
  //     mousePos.y > 50 && mousePos.y < 650) {
  // }
}

Bullet WeaponClickable::getBullet(Vector2 target) {
  Vector2 dirr;
  if (target.x > target.y) {
    dirr.x = (target.x > 0.0) ? 3000.0 : -3000.0;
    dirr.y = target.y / std::abs(target.x) * 3000;
  } else {
    dirr.x = target.x / std::abs(target.y) * 3000;
    dirr.y = (target.y > 0.0) ? 3000.0 : -3000.0;
  }
  Bullet bullet{m_dp, {0, 0}, dirr, 20.0, 10.0, WHITE};
  return bullet;
}

void WeaponClickable::renderButton(float cash) {
  Color lineColor = cash >= m_weaponUpdateCost ? DARKGRAY : LIGHTGRAY;
  DrawRectangleLinesEx({700, 50, 250, 50}, 2, lineColor);
  DrawText("Pea shooter", 720, 65, 20, lineColor);
  DrawText(std::to_string(int(m_weaponUpdateCost)).c_str(), 900, 65, 20,
           lineColor);
}

void WeaponClickable::buyWeaponUpdate() {
  m_dp++;
  m_weaponUpdateCost *= 1.5;
}

float WeaponClickable::getWeaponUpdateCost() { return m_weaponUpdateCost; }
bool WeaponClickable::isArenaHovered() { return m_isArenaHovered; }
bool WeaponClickable::isButtonHovered() { return m_isButtonHovered; }
bool WeaponClickable::isBulletReady() { return m_bulletReady; }
int WeaponClickable::getDp() { return m_dp; }
Vector2 WeaponClickable::getPos() { return m_pos; }
Color WeaponClickable::getColor() { return m_color; }
