#include "Weapon.h"
#include "raylib.h"
#include <cstdlib>
#include <iostream>

bool WeaponClickable::isMouseOnArena() {

  Vector2 mousePos = GetMousePosition();
  return mousePos.x > 50 && mousePos.x < 650 && mousePos.y > 50 &&
         mousePos.y < 650;
}

void WeaponClickable::update() {
  m_isHovered = isMouseOnArena();

  if (m_isHovered)
    SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
  else
    SetMouseCursor(MOUSE_CURSOR_ARROW);

  // if (m_isHovered && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
  m_bulletReady = (m_isHovered && IsMouseButtonPressed(MOUSE_BUTTON_LEFT));
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
  // std::cout << target.x << " " << target.y << " " << dirr.x << " " << dirr.y
  //           << std::endl;
  Bullet bullet{1, {0, 0}, dirr, 20.0, 10.0, WHITE};
  return bullet;
}

bool WeaponClickable::isHovered() { return m_isHovered; }
bool WeaponClickable::isBulletReady() { return m_bulletReady; }
int WeaponClickable::getDp() { return m_dp; }
Vector2 WeaponClickable::getPos() { return m_pos; }
Color WeaponClickable::getColor() { return m_color; }
