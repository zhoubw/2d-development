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
  
  loadAllTextures();
  Player p(1280/2,720/2);
  Projectiles.push_back(new Projectile (1280/2, 100, 90.f));

  //gameloop
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


    world.Step(1/FPS, 8, 3);
    window.clear(sf::Color::White);

    //player step
    p.step(window);

    //projectiles step
    //prj.step(window);
    for (prjIterator=Projectiles.begin(); prjIterator!=Projectiles.end();++prjIterator) {
      (*prjIterator)->step(window);
    }

    window.display();
  }

  return 0;
}
