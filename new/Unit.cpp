#include "Unit.hpp"

Unit::Unit(int x, int y) {
  this->x = x;
  this->y = y;
  this->width = width;
  this->height = height;
  
  this->speed = speed;
  
  /*
  BodyDef.position = b2Vec2(x/SCALE, y/SCALE);
  BodyDef.type = b2_kinematicBody;
  Body = world.CreateBody(&BodyDef);
 
  Shape.SetAsBox((width/2)/SCALE, (height/2)/SCALE);
  FixtureDef.density = 1.f;
  FixtureDef.friction = 0.7f;
  FixtureDef.shape = &Shape;
  Body->CreateFixture(&FixtureDef);

  sprite.setTexture(playerTexture);
  sprite.setOrigin(width/2, height/2);
  sprite.setPosition(SCALE*x, SCALE*y);
  //sprite.setRotation(Body.GetAngle() * 180/b2_pi);
  */

}
