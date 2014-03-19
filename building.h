#ifndef __BUILDING_H__
#define __BUILDING_H__
struct Building {
  int x;
  int y;
  unsigned height;

  Building(int x, int y, unsigned height) : x(x), y(y), height(height) {}
};
#endif
