#include "main.hpp"

sf::RenderWindow window(sf::VideoMode(1280, 720), "Title goes here");

//Collections and iterators
std::vector<Unit*> Units;
std::vector<Unit*>::iterator unitIterator;

//Textures
sf::Texture defaultUnitTexture;
sf::Texture HPRed;
sf::Texture HPGreen;

//If game is running
bool running = false;

//init these somewhere else later
int totalFrame = 0;
sf::Time frameGap = sf::milliseconds(1000/60);


void gameLoop(sf::Clock clock, sf::Time frameGap) {
  Gui gui(window);
  loadAllTextures();
  Units.push_back(new Unit(sf::String("Footman"),1280/2,720/2,90,100,100,100));
  Units.push_back(new Unit(sf::String("Archer"),800, 720/2, 90, 200, 200, 200));
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

      //reset window
      window.clear();

      //step
      gui.step(window);

      //draws new stuff	
      for (unitIterator=Units.begin();unitIterator!=Units.end();++unitIterator) {
	//window.draw((*unitIterator)->sprite);
	(*unitIterator)->step(window);
      }
      
      //display new stuff
      window.display();
    }
  }
} //end gameLoop()

void loadAllTextures() {
  defaultUnitTexture.loadFromFile("defaultTexture.png");
  HPGreen.loadFromFile("HPGreen.png");
  HPRed.loadFromFile("HPRed.png");
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
      
      running = true;

      if (running) {
	gameLoop(clock,frameGap);
      }
    }
  

  return 0;
}
