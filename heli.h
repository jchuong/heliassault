#ifndef __HELI_H__
#define __HELI_H__

#include "game.h"

class Helicopter
{
  private:
    int X_MAX_SPEED = 7;
    int Y_MAX_SPEED = 7;
    unsigned x;
    unsigned y;
    int x_speed;
    int y_speed;
    int hp;

    // Protect the class from strange modifications
    Helicopter();
    Helicopter operator=(const Helicopter&);
  public:
    Helicopter(unsigned x, unsigned y, int hp);

    void Move_Left(double update_percent);
    void Move_Right(double update_percent);
    void Move_Up(double update_percent);
    void Move_Down(double update_percent);
    void Stop_Horizontal(void);
    void Stop_Vertical(void);
    void Update_Location();
    void Update_Speed(BUTTON_STATE move_state);
    void Shoot(void);
    void Take_Damage(int damage);

    void Get_Location(unsigned* x, unsigned* y) const;
    int Get_HP(void) const;
};
#endif // __HELI_H__
