#include "Player.hpp"

int playerSpeed = 3.f;

Player::Player(int x, int y):Unit(x,y,playerSpeed,32.f,32.f) {
  HP = 100;
  maxHP = 100;
  HPBar = 100;

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

}

void Player::step(sf::RenderWindow& window) {
  x = Body->GetPosition().x;
  y = Body->GetPosition().y;
  sprite.setPosition(SCALE*x,SCALE*y);
  window.draw(sprite);
}
