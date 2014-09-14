#include "Projectile.hpp"

int projSpeed = 7.f;

Projectile::Projectile(int x, int y, float heading):Unit(x,y,projSpeed,12.f,11.f) {
  this->heading = heading;

  BodyDef.position = b2Vec2(x/SCALE, y/SCALE);
  BodyDef.angle = heading * b2_pi / 180;
  BodyDef.type = b2_kinematicBody;
  Body = world.CreateBody(&BodyDef);
  
  Shape.SetAsBox((width/2)/SCALE, (height/2)/SCALE);
  FixtureDef.density = 1.f;
  FixtureDef.friction = 0.7f;
  FixtureDef.shape = &Shape;
  Body->CreateFixture(&FixtureDef);
  
  sprite.setTexture(blueBulletTexture);
  sprite.setOrigin(width/2, height/2);
  sprite.setPosition(SCALE*x, SCALE*y);
  sprite.setRotation(Body->GetAngle() * 180/b2_pi);

}

void Projectile::step(sf::RenderWindow& window) {
  b2Vec2 vel = Body->GetLinearVelocity();
  vel.x = speed * cos(Body->GetAngle());
  vel.y = speed * sin(Body->GetAngle());
  Body->SetLinearVelocity(vel);

  x = Body->GetPosition().x * SCALE;
  y = Body->GetPosition().y * SCALE;
  heading = Body->GetAngle() * 180/b2_pi;

  sprite.setRotation(heading);
  sprite.setPosition(x,y);
  window.draw(sprite);
}
