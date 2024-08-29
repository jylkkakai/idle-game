#ifndef TOWERWEAPON_H
#define TOWERWEAPON_H
#include <raylib.h>

struct Tower {
  Vector2 pos = {0, 0};
  float towerRadius = 100.0;
  Color towerColor = LIGHTGRAY;
  float visionRadius = 1000.0;
  Color visionRadiusColor = DARKGRAY;

  float hp = 50;
};

class TowerWeapon {
public:
  TowerWeapon();
  TowerWeapon(int dp, Color color);
  ~TowerWeapon();

  void update();

private:
  int m_dp;
  Color m_ammoColor;
};
#endif // !TOWERWEAPON_H
