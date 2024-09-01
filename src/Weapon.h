#ifndef WEAPON_H
#define WEAPON_H
#include "Bullet.h"
#include <raylib.h>

class WeaponClickable {
public:
  void update();
  void buyWeaponUpdate();
  bool isArenaHovered();
  bool isButtonHovered();
  bool isBulletReady();
  // int getDp();
  // Vector2 getPos();
  // Color getColor();
  Bullet getBullet(Vector2 target);
  float getWeaponUpdateCost();
  void renderButton(float cash);

private:
  int m_dp = 1;
  Vector2 m_pos = {0, 0};
  Color m_color = WHITE;
  bool m_bulletReady = false;
  bool m_isArenaHovered = false;
  bool m_isButtonHovered = false;
  float m_weaponUpdateCost = 100.0;
  int m_weaponLevel = 1;

  bool isMouseOnArena();
  bool isMouseOnButton();
};

class WeaponAutomatic {
public:
  void update();
  void buyWeaponUpdate();
  bool isButtonHovered();
  bool isBulletReady();
  // int getDp();
  // Vector2 getPos();
  // Color getColor();
  Bullet getBullet(Vector2 target);
  float getWeaponUpdateCost();
  void renderButton(float cash);

private:
  int m_dp = 5;
  Vector2 m_pos = {0, 0};
  Color m_color = YELLOW;
  bool m_bulletReady = false;
  bool m_isButtonHovered = false;
  float m_weaponUpdateCost = 500.0;
  int m_weaponLevel = 0;

  bool isMouseOnButton();
};
#endif // !WEAPON_H
