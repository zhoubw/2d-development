#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <iostream>

extern const float SCALE;
extern sf::Texture playerTexture;
extern b2World world;

class Player {
public:
  int x, y;
  float speed;
  float width;
  float height;
  
  int hp;
  int maxHp;
  int hpBar;
  Player(int x, int y);

  b2BodyDef BodyDef;
  b2Body* Body;
  b2PolygonShape Shape;
  b2FixtureDef FixtureDef;

  sf::Sprite sprite;
};
#endif
