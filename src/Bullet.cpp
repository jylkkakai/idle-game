#include "Bullet.h"
#include <raymath.h>

void Bullet::updatePos() { pos = Vector2MoveTowards(pos, dir, speed); }
