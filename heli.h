#ifndef __HELI_H__
#define __HELI_H__
class Helicopter
{
  private:
    unsigned x;
    unsigned y;
    int hp;
    double scale;

    // Protect the class from strange modifications
    Helicopter();
    Helicopter operator=(const Helicopter&);
  public:
    Helicopter(unsigned x, unsigned y, int hp, double scale);

    void Move_Left(void);
    void Move_Right(void);
    void Move_Up(void);
    void Move_Down(void);
    void Shoot(void);
    void Take_Damage(int damage);

    void Set_Scale(double scale);

    void Get_Location(unsigned* x, unsigned* y) const;
    int Get_HP(void) const;
};
#endif // __HELI_H__
