#include <cassert>

#include "heli.h"
Helicopter::Helicopter(unsigned x, unsigned y, int hp, double scale) :
  x(x), y(y), scale(scale)
{
  // Unfortunately, by being able to use negative hp damage, we either deal with unsigned
  // and signed ints for HP, so we need to do this check so avoid any instant death.
  assert(hp > 0);
  this->hp = hp;
}

void Helicopter::Move_Left(void)
{
  x = x - 5 * scale;
}
