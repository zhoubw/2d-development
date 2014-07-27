#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <iostream>
#include "Player.hpp"
#include "Camera.cpp"
#include "MapGrid.hpp"
#include "main.hpp"

sf::RenderWindow window(sf::VideoMode(w, h), "Title goes here");
int main()
{
  Camera camera;
  Player p(50,0);
  //window.create( sf::VideoMode(camera.dim_x, camera.dim_y, "Title goes here") );
  //sf::RenderWindow window(sf::VideoMode(camera.dim_x, camera.dim_y), "Title goes here");

  //sf::CircleShape shape(100.f);
  //shape.setFillColor(sf::Color::Green);
  //printBlockSprites();
  sf::Clock clock;
  sf::Time frameGap = sf::milliseconds(1000/60);
  int totalFrame = 0;

  //NEVER SYNC WITH COMPUTER AND USE THIS AT THE SAME TIME! EVER!
  window.setFramerateLimit(60);

  //KEYS
  bool left = false;
  bool right = false;
  bool space = false;
  //test
  bool up = false;
  bool down = false;
  
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
      //testing buttons
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
	up = true;
      }
      else
	up = false;
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
	down = true;
      }
      else
	down = false;
      

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
	//test*******erase later
	//std::cout << "Frame " << totalFrame << std::endl;
	//timer reset
	clock.restart();
	totalFrame++;
	
	//key response
	if (left == true)
	  //p.move(p.speed*-1,0);
	  p.dX = (p.speed*-1);
	else if (right == true)
	  p.dX = p.speed;
	else
	  p.dX = 0;
	if (space == true)
	  p.jump();

	//testing buttons
	if (up == true)
	  p.move(0,-1);
	//std::cout << "( " << p.x << ", " << p.y << " )" << std::endl;
	if (down == true)
	  p.move(0,1);
	
	//misc.
	p.fall();
	p.step();

	//reset window
	window.clear();

	//draws new stuff	
	camera.mainView.setCenter(p.x,p.y);
	window.setView(camera.mainView);
	//window.draw(p.currentSprite);
	window.draw(camera.map);
	fill200();
	window.draw(p.shape); 
	
	//display new stuff
	window.display();
      }
    }

  return 0;
}
