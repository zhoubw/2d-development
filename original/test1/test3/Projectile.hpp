#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <iostream>

extern const float SCALE;
extern sf::Texture blueBulletTexture;
extern b2World world;

class Projectile {
public:
  int x,y;
  float speed;
  float width;
  float height;
  float heading;
  
  Projectile(std::string type, int x, int y, float heading, float speed);
  
  b2BodyDef BodyDef;
  b2Body* Body;
  b2PolygonShape Shape;
  b2FixtureDef FixtureDef;
  
  sf::Sprite sprite;
};
#endif
