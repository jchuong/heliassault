#include <cassert>

#include "heli.h"
Helicopter::Helicopter(unsigned x, unsigned y, int hp) :
  x(x), y(y)
{
  // Unfortunately, by being able to use negative hp damage, we either deal with unsigned
  // and signed ints for HP, so we need to do this check so avoid any instant death.
  assert(hp > 0);
  this->hp = hp;
}

void Helicopter::Move_Left(void)
{
  x = x - 10;
}

void Helicopter::Move_Right(void)
{
  x = x + 10;
}

void Helicopter::Move_Up(void)
{
  y = y - 10;
}

void Helicopter::Move_Down(void)
{
  y = y + 10;
}

void Helicopter::Shoot(void)
{
  // TODO: Add bullet class, maybe this is not needed here
}

void Helicopter::Take_Damage(int damage)
{
  hp = hp - damage;
}

void Helicopter::Get_Location(unsigned* x, unsigned* y) const
{
  assert(x != 0);
  assert(y != 0);
  *x = this->x;
  *y = this->y;
}

int Helicopter::Get_HP(void) const
{
  return hp;
}
