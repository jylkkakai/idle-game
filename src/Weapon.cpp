#include "Weapon.h"
#include "raylib.h"
#include <cmath>
#include <cstdlib>
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
  m_bulletReady = (m_isArenaHovered && IsMouseButtonPressed(MOUSE_BUTTON_LEFT));
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
  Bullet bullet{m_dp, {0, 0}, dirr, 20.0, 10.0, m_color};
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
  m_weaponLevel++;
  m_dp = m_weaponLevel + 10 * (m_weaponLevel / 10);
  m_weaponUpdateCost *= 1.5;
}

float WeaponClickable::getWeaponUpdateCost() { return m_weaponUpdateCost; }
bool WeaponClickable::isArenaHovered() { return m_isArenaHovered; }
bool WeaponClickable::isButtonHovered() { return m_isButtonHovered; }
bool WeaponClickable::isBulletReady() { return m_bulletReady; }
// int WeaponClickable::getDp() { return m_dp; }
// Vector2 WeaponClickable::getPos() { return m_pos; }
// Color WeaponClickable::getColor() { return m_color; }

bool WeaponAutomatic::isMouseOnButton() {

  Vector2 mousePos = GetMousePosition();
  return mousePos.x > 700 && mousePos.x < 950 && mousePos.y > 150 &&
         mousePos.y < 200;
}

void WeaponAutomatic::update() {
  static int frameCounter = 0;
  static int framesToBullet = 60;
  m_isButtonHovered = isMouseOnButton();

  if (frameCounter >= framesToBullet) {
    m_bulletReady = true;
    frameCounter = 0;
  }
  if (m_weaponLevel > 0 && !m_bulletReady)
    frameCounter++;
}

Bullet WeaponAutomatic::getBullet(Vector2 target) {
  Vector2 dirr;
  if (target.x > target.y) {
    dirr.x = (target.x > 0.0) ? 3000.0 : -3000.0;
    dirr.y = target.y / std::abs(target.x) * 3000;
  } else {
    dirr.x = target.x / std::abs(target.y) * 3000;
    dirr.y = (target.y > 0.0) ? 3000.0 : -3000.0;
  }
  Bullet bullet{m_dp, {0, 0}, dirr, 20.0, 10.0, m_color};
  m_bulletReady = false;
  return bullet;
}

void WeaponAutomatic::renderButton(float cash) {
  Color lineColor = cash >= m_weaponUpdateCost ? DARKGRAY : LIGHTGRAY;
  DrawRectangleLinesEx({700, 150, 250, 50}, 2, lineColor);
  DrawText("Slingshot", 720, 165, 20, lineColor);
  DrawText(std::to_string(int(m_weaponUpdateCost)).c_str(), 900, 165, 20,
           lineColor);
}

void WeaponAutomatic::buyWeaponUpdate() {
  m_weaponLevel++;
  m_dp = 5 * pow(1.5, m_weaponLevel);
  m_weaponUpdateCost *= 1.5;
}

float WeaponAutomatic::getWeaponUpdateCost() { return m_weaponUpdateCost; }
bool WeaponAutomatic::isButtonHovered() { return m_isButtonHovered; }
bool WeaponAutomatic::isBulletReady() { return m_bulletReady; }
// int WeaponAutomatic::getDp() { return m_dp; }
// Vector2 WeaponAutomatic::getPos() { return m_pos; }
// Color WeaponAutomatic::getColor() { return m_color; }
