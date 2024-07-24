#ifndef TOWERWEAPON_H
#define TOWERWEAPON_H
#include <raylib.h>

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
