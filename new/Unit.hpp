#ifndef UNIT_HPP
#define UNIT_HPP
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <iostream>

extern const float SCALE;
extern sf::Texture playerTexture;
extern b2World world;

class Unit {
public:
  int x, y;
  float speed;
  float width;
  float height;

  Unit(int x, int y, float speed, float width, float height);
  
  b2BodyDef BodyDef;
  b2Body* Body;
  b2PolygonShape Shape;
  b2FixtureDef FixtureDef;

  sf::Sprite sprite;
};
#endif
