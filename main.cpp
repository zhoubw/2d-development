#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <iostream>
#include "Player.hpp"
#include "Camera.cpp"
#include "MapGrid.hpp"
#include "main.hpp"

sf::RenderWindow window(sf::VideoMode(w, h), "Title goes here");

//If game is running
bool running = false;

//KEYS
bool left = false;
bool right = false;
bool space = false;

//init these somewhere else later
Camera camera;
Player p(50,0);
int totalFrame = 0;
sf::Time frameGap = sf::milliseconds(1000/60);

//pass some parameters at some point
//one of them being map...?
void gameLoop(sf::Clock clock, sf::Time frameGap) {
  /******************v NECESSARY STUFF v*********************/
  while (running) {
    /***********************v Keyboard v*********************/
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
      /***********************^ Keyboard ^*********************/
      
      sf::Event event;
      while (window.pollEvent(event)) {
	switch (event.type) {
	case sf::Event::Closed:
	  window.close();
	  break;
	}
      }
      
/******************^ NECESSARY STUFF ^*********************/

    //*****if one frame completes
    if (clock.getElapsedTime() >= frameGap) {
      //timer reset
      clock.restart();
      totalFrame++;
	
      //key response
      if (left == true)
	p.dX = (p.speed*-1);
      else if (right == true)
	p.dX = p.speed;
      else
	p.dX = 0;
      if (space == true)
	p.jump();
	
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
      drawMap();
      window.draw(p.shape); 
	
      //display new stuff
      window.display();
    }
  }
}

int main()
{  
  sf::Clock clock;


  //NEVER SYNC WITH COMPUTER AND USE THIS AT THE SAME TIME! EVER!
  window.setFramerateLimit(60);

  window.clear();
  window.display();
  
  //Window loop
  while (window.isOpen())
    {
      /***********************v Keyboard v*********************/
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
      /***********************^ Keyboard ^*********************/

      //handles events
      sf::Event event;
      while (window.pollEvent(event)) {
	switch (event.type) {
	case sf::Event::Closed:
	  window.close();
	  break;
	}
      }

      //Main Menu
      //By default, start at the menu.
      
      if (space)
	running = true;

      if (running) {
	fill200();
	gameLoop(clock,frameGap);
      }
    }
  

  return 0;
}
