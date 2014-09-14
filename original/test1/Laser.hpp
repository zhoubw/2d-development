//Header file for Laser
#ifndef LASER_HPP
#define LASER_HPP
#include "Projectile.hpp"

extern Player p;
extern Mirror mirror;

class Laser: public Projectile {
public:
  bool reflected;
  Laser(std::string source,int width,int height,int x_cor,int y_cor,int heading,int speed);
  virtual void move(int x, int y); //inherited
  bool hitMirror(Mirror mirror);
};
#endif
