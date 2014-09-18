#include "main.hpp"

sf::RenderWindow window(sf::VideoMode(w, h), "Title goes here");

//If game is running
bool running = false;

//init these somewhere else later
Camera camera;
int totalFrame = 0;
sf::Time frameGap = sf::milliseconds(1000/60);


void gameLoop(sf::Clock clock, sf::Time frameGap) {

  while (running) {
    /******************v NECESSARY STUFF v*********************/
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
	
      //misc.

      //reset window
      window.clear();

      //draws new stuff	
      //camera.mainView.setCenter(p.x,p.y);
      //window.setView(camera.mainView);
      //window.draw(p.currentSprite);
      //window.draw(camera.map);
      //drawMap();
      //window.draw(p.shape); 
	
      //display new stuff
      window.display();
    }
  }
} //end gameLoop()

void loadAllTextures() {
  defaultUnitTexture.loadFromFile("defaultTexture.png");
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
      
      //TEST*******
      if (space)
	running = true;

      if (running) {
	gameLoop(clock,frameGap);
      }
    }
  

  return 0;
}
