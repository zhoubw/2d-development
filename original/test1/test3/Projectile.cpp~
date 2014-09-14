#include "Projectile.hpp"

Projectile::Projectile(std::string type="blueBullet", int x = 1280/2, int y = 100, float heading = 270.f, float speed = 10.f) {
  this->x = x;
  this->y = y;
  width = 10.f;
  height = 11.f;
  
  this->speed = speed;
  this->heading = heading;
  
  BodyDef.position = b2Vec2(x/SCALE, y/SCALE);
  //tbd - heading is counterclockwise in box2d
  BodyDef.angle = heading * b2_pi / 180;
  BodyDef.type = b2_dynamicBody; //prob change this
  Body = world.CreateBody(&BodyDef);

  Shape.SetAsBox((width/2)/SCALE, (height/2)/SCALE);
  //tbd
  FixtureDef.density = 1.f;
  FixtureDef.friction = 0.7f;
  FixtureDef.shape = &Shape;
  Body->CreateFixture(&FixtureDef);

  if (type == "blueBullet") {
    sprite.setTexture(blueBulletTexture);
  }
  sprite.setOrigin(width/2, height/2);
  sprite.setPosition(SCALE*x, SCALE*y);
  //needs testing
  sprite.setRotation(heading);
  sprite.setRotation(Body->GetAngle() * 180/b2_pi);
}
