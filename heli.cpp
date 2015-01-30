#include <cassert>
#include <algorithm>

#include "heli.h"
#include "game.h"
Helicopter::Helicopter(unsigned x, unsigned y, int hp) :
  x(x), y(y), x_speed(0), y_speed(0)
{
  // Unfortunately, by being able to use negative hp damage, we either deal with unsigned
  // and signed ints for HP, so we need to do this check so avoid any instant death.
  assert(hp > 0);
  this->hp = hp;
}

void Helicopter::Move_Left(double update_percent)
{
  x_speed = -X_MAX_SPEED * update_percent;
}

void Helicopter::Move_Right(double update_percent)
{
  x_speed = X_MAX_SPEED * update_percent;
}

void Helicopter::Move_Up(double update_percent)
{
  y_speed = -Y_MAX_SPEED * update_percent;
}

void Helicopter::Move_Down(double update_percent)
{
  y_speed = Y_MAX_SPEED * update_percent;
}

void Helicopter::Stop_Horizontal(void)
{
  x_speed = 0;
}

void Helicopter::Stop_Vertical(void)
{
  y_speed = 0;
}

void Helicopter::Update_Speed(BUTTON_STATE move_state)
{
  if (~(move_state & UP & DOWN))
  {
    Stop_Vertical();
  }
  if (~(move_state & LEFT & DOWN))
  {
    Stop_Horizontal();
  }
  if (move_state & UP)
  {
    Move_Up(1);
  }
  if (move_state & DOWN)
  {
    Move_Down(1);
  }
  if (move_state & RIGHT)
  {
    Move_Right(1);
  }
  if (move_state & LEFT)
  {
    Move_Left(1);
  }
}

void Helicopter::Update_Location(void)
{
  x = std::min((unsigned)std::max((int)x + x_speed, 0), ORIGINAL_WIDTH - HELICOPTER_WIDTH);
  y = std::min((unsigned)std::max((int)y + y_speed, 0), ORIGINAL_HEIGHT - HELICOPTER_HEIGHT);
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
