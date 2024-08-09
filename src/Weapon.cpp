#include "Weapon.h"
#include "raylib.h"

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
}

bool WeaponClickable::isHovered() { return m_isHovered; }
bool WeaponClickable::isBulletReady() { return m_bulletReady; }
int WeaponClickable::getDp() { return m_dp; }
Vector2 WeaponClickable::getPos() { return m_pos; }
Color WeaponClickable::getColor() { return m_color; }
