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
    world.Step(1/FPS, 8, 3);
    window.clear(sf::Color::White);

    window.display();
  }

  return 0;
}
