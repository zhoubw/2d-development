#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <iostream>
#include "Player.hpp"
#include "Camera.cpp"

int main()
{
  Camera camera;
  Player p(0,0);
  sf::RenderWindow window(sf::VideoMode(1024, 768), "Title goes here");
  //sf::CircleShape shape(100.f);
  //shape.setFillColor(sf::Color::Green);

  sf::Clock clock;
  sf::Time frameGap = sf::milliseconds(1000/60);
  int totalFrame = 0;

  //NEVER SYNC WITH COMPUTER AND USE THIS AT THE SAME TIME! EVER!
  window.setFramerateLimit(60);

  //KEYS
  bool left = false;
  bool right = false;
  bool space = false;
  
  // window.setView(camera.mainView);

  window.clear();
  window.display();

  while (window.isOpen())
    {
      //Keyboard	
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
	left = true;
      }
      else
	left = false;
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
	right = true;
      }
      else
	right = false;
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
	space = true;
      }
      else
	space = false;
      

      //handles events
      sf::Event event;
      while (window.pollEvent(event)) {
	switch (event.type) {
	
	case sf::Event::Closed:
	  window.close();
	  break;
	}
      }

      //*****if one frame completes
      if (clock.getElapsedTime() >= frameGap) {
	//timer reset
	clock.restart();
	totalFrame++;

	//key response
	if (left == true)
	  p.move(p.speed*-1,0);
	if (right == true)
	  p.move (p.speed,0);
	if (space == true)
	  p.jump();

	//misc.
	p.fall();

	//reset window
	window.clear();

	//draws new stuff	
	camera.mainView.setCenter(p.x+(p.width/2),p.y+(p.height/2));
	window.setView(camera.mainView);
	//window.draw(p.currentSprite);
	window.draw(camera.map);
	window.draw(p.shape); 
	
	//display new stuff
	window.display();
      }
    }

  return 0;
}
