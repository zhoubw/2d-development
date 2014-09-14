//Header file for Projectile
#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP
#include "Player.hpp"
#include "Mirror.hpp"

extern Player p;
extern Mirror mirror;

class Projectile {
public:
  std::string source;
  int x, y;
  int heading;
  float headingRad;
  int speed, dX, dY;
  int width;
  int height;

  bool isAlive;

  sf::Texture texture;
  sf::Sprite sprite;
  virtual void move(int x,int y); //inherited by Laser
  void step();
  bool hitPlayer(Player p);
  void retexture();
  Projectile(std::string source,int width,int height,int x_cor,int y_cor,int heading,int speed);

};
#endif
