#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP
#include "Unit.hpp"
#include <math.h>

extern sf::Texture blueBulletTexture;

class Projectile: public Unit {
public:
  float heading;
  Projectile(int x, int y, float heading);
  void step(sf::RenderWindow& window);
  
};

#endif
