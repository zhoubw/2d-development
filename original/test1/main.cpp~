#include <iostream>
#include "main.hpp"
#include <memory>
const int width = 1280;
const int height = 720;

sf::RenderWindow window(sf::VideoMode(width, height), "Title goes here");

//If game is running
bool running = false;

//KEYS
bool left = false;
bool right = false;
bool up = false;
bool down = false;
bool w = false;
bool a = false;
bool s = false;
bool d = false;

//global (externs)
Player p(1200, 720/2);
Mirror mirror(p);
std::vector<Projectile*> Projectiles;
//Projectile prj("blueBullet.png",10,10,1024/2,100,270,2);

int totalFrame = 0;
sf::Time frameGap = sf::milliseconds(1000/60);

//pass some parameters at some point
//one of them being map...?
void gameLoop(sf::Clock clock, sf::Time frameGap) {
  std::vector<Projectile*>::iterator prjIterator;

   /*
  for (int i=0;i<9;i++) {
    Projectile prj("blueBullet.png",10,11,1280/2,720/2,(360/8)*i,2);
    Projectiles.push_back(prj);
  }
  */

  // for (int i=0;i<9;i++) {
  //Projectiles.push_back(new Laser("blueBullet.png",10,11,1280/2,720/2,(360/8)*i,10));
  //}

  Projectiles.push_back(new Projectile("blueBullet.png",10,11,1280/2,720/2,0, 20));

  //When an object is pushed, it loses its texture and must be retextured
  //OBSOLETE
  //for (prjIterator=Projectiles.begin(); prjIterator!=Projectiles.end(); ++prjIterator) {
  //(*prjIterator)->retexture();
  // }
  
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
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
	w = true;
      }
      else
	w = false;
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
	a = true;
      }
      else
	a = false;
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
	s = true;
      }
      else
	s = false;
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
	d = true;
      }
      else
	d = false;
      
      //gets the mouse coordinates
      mirror.mouseX = sf::Mouse::getPosition(window).x;
      mirror.mouseY = sf::Mouse::getPosition(window).y;

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
	
      //key response: arrows or wasd
      if (left || a)
	p.dX = (p.speed*-1);
      else if (right || d)
	p.dX = p.speed;
      else
	p.dX = 0;

      if (up || w)
	p.dY = (p.speed*-1);
      else if (down || s)
	p.dY = p.speed;
      else
	p.dY = 0;

      //movement****************************************
      p.step();
      mirror.step(p, mirror.mouseX, mirror.mouseY);
      /****v Projectiles v****/
      for (prjIterator=Projectiles.begin(); prjIterator!=Projectiles.end(); ++prjIterator) {
	(*prjIterator)->step();
      }
      /****^ Projectiles ^****/

      //reset window
      window.clear();

      //draws new stuff*********************************	
      window.draw(p.shape);
      window.draw(mirror.sprite);

      //testing an hp bar
      window.draw(p.hpSprite);


      /****v Projectiles v****/
      for (prjIterator=Projectiles.begin(); prjIterator!=Projectiles.end(); ++prjIterator) {
	window.draw((*prjIterator)->sprite);
      }
      /****^ Projectiles ^****/

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
      //keyboard for outside of gameloop stuff
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
      
      //if (something happens)
      running = true;

      if (running) {
	gameLoop(clock,frameGap);
      }
    }
  

  return 0;
}
