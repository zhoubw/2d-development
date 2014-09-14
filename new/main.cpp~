#include "main.hpp"

/** Prepare the window **/
sf::RenderWindow window(sf::VideoMode(WIDTH,HEIGHT), "Using Box2D");
sf::Texture playerTexture;
sf::Texture blueBulletTexture;


b2Vec2 gravity(0.f, 0.f);
b2World world(gravity);

void loadAllTextures() {
  playerTexture.loadFromFile("box.png");
  blueBulletTexture.loadFromFile("blueBullet.png");
}

int main() {
  window.setFramerateLimit(60);

  //gameloop
  //test player
  loadAllTextures();
  std::vector<Projectile*> Projectiles;
  std::vector<Projectile*>::iterator prjIterator;

  Player p(WIDTH/2, HEIGHT/2);
  //test Projectile
  //Projectile proj ("blueBullet", WIDTH/2, 100, 180.f, 10.f);
  for (int i=0; i<12; i++) { 
  /**********big problem with dynamic bodies*/
    Projectiles.push_back(new Projectile("blueBullet", WIDTH/2 + 10 * cos(i*(360/12.f) * b2_pi / 180), 100 + 10 * sin(i*(360/12.f) * b2_pi / 180), i*(360/12.f), 10.f));
  }  

  while (window.isOpen()) {

    //handles events
    sf::Event event;
    while (window.pollEvent(event)) {
      switch (event.type) {
      case sf::Event::Closed:
	window.close();
	break;
      }
    }
    
    b2Vec2 playerVel = p.Body->GetLinearVelocity();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
      playerVel.x = -p.speed;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
      playerVel.x = p.speed;
    }
    else {
      playerVel.x = 0;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
      playerVel.y = -p.speed;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
      playerVel.y = p.speed;
    }
    else {
      playerVel.y = 0;
    }
    
    p.Body->SetLinearVelocity(playerVel);

    /*
    b2Vec2 projVel = proj.Body->GetLinearVelocity();
    projVel.x = proj.speed * cos(proj.heading * b2_pi / 180);
    projVel.y = proj.speed * sin(proj.heading * b2_pi / 180);
    proj.Body->SetLinearVelocity(projVel);
    */
    for (prjIterator = Projectiles.begin(); prjIterator!=Projectiles.end();++prjIterator) {
      b2Vec2 projVel = (*prjIterator)->Body->GetLinearVelocity();
      projVel.x = (*prjIterator)->speed * cos((*prjIterator)->heading * b2_pi / 180);
      projVel.y = (*prjIterator)->speed * sin((*prjIterator)->heading * b2_pi / 180);
      (*prjIterator)->Body->SetLinearVelocity(projVel);
    }

    world.Step(1/FPS, 8, 3);
    window.clear(sf::Color::White);


    /*
    for (b2Body* BodyIterator = world.GetBodyList(); BodyIterator != 0; BodyIterator = BodyIterator->GetNext())
      {
	if (BodyIterator->GetType() == b2_dynamicBody)
	  {
	    p.sprite.setPosition(SCALE * BodyIterator->GetPosition().x, SCALE * BodyIterator->GetPosition().y);
	    p.sprite.setRotation(BodyIterator->GetAngle() * 180/b2_pi);
	    window.draw(p.sprite);
	  }
      }
    */
    
    /** Draw Sprites **/
    //1. configure position
    p.sprite.setPosition(SCALE * p.Body->GetPosition().x, SCALE * p.Body->GetPosition().y);
    //proj.sprite.setPosition(SCALE * proj.Body->GetPosition().x, SCALE * proj.Body->GetPosition().y);
    //2. configure rotation
    p.sprite.setRotation(p.Body->GetAngle() * 180/b2_pi);
    //proj.sprite.setRotation(proj.Body->GetAngle() * 180/b2_pi);
    //need a way to change heading var.
    //3. Draw
    window.draw(p.sprite);
    //window.draw(proj.sprite);
    
    for (prjIterator=Projectiles.begin(); prjIterator!=Projectiles.end(); ++prjIterator) {
      (*prjIterator)->sprite.setPosition(SCALE * (*prjIterator)->Body->GetPosition().x, SCALE * (*prjIterator)->Body->GetPosition().y);
      (*prjIterator)->sprite.setRotation((*prjIterator)->Body->GetAngle() * 180/b2_pi);
      window.draw ((*prjIterator)->sprite);
    }
    
    /**/
    window.display();
  }

  return 0;
}
