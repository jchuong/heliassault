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

void Helicopter::Move_Right(void)
{
  x = x + 5 * scale;
}

void Helicopter::Move_Up(void)
{
  y = y - 5 * scale;
}

void Helicopter::Move_Down(void)
{
  x = x - 5 * scale;
}

void Helicopter::Shoot(void)
{
  // TODO: Add bullet class, maybe this is not needed here
}

void Helicopter::Take_Damage(int damage)
{
  hp = hp - damage;
}

void Helicopter::Set_Scale(double scale)
{
  this->scale = scale;
  // Have to move the location relative to the scale
  x = x * scale;
  y = y * scale;
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
