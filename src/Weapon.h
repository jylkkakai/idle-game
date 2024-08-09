#ifndef WEAPON_H
#define WEAPON_H
#include <raylib.h>

class WeaponClickable {
public:
  // WeaponClickable();

  void update();
  bool isHovered();
  bool isBulletReady();
  int getDp();
  Vector2 getPos();
  Color getColor();

private:
  int m_dp = 1;
  Vector2 m_pos = {0, 0};
  Color m_color = WHITE;
  bool m_bulletReady = false;
  bool m_isHovered = false;

  bool isMouseOnArena();
};

// WeaponClickable::WeaponClickable() {}

// WeaponClickable::~WeaponClickable() {}

#endif // !WEAPON_H
