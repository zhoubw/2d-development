#include "main.hpp"

sf::RenderWindow window(sf::VideoMode(1280, 720), "Title goes here");
Gui gui(window);
Game game;

//Textures
sf::Texture defaultUnitTexture;
sf::Texture HPRed;
sf::Texture HPGreen;
sf::Texture whiteTile;
sf::Texture redTile;
sf::Texture blueTile;

//If game is running
bool running = false;

//init these somewhere else later
int totalFrame = 0;
sf::Time frameGap = sf::milliseconds(1000/60);


void gameLoop(sf::Clock clock, sf::Time frameGap) {

  loadAllTextures();
  //push units
  p1Units.push_back(new Unit(sf::String("Footman"),1280/2,1,90,100,100,500,0));
  p2Units.push_back(new Unit(sf::String("Archer"),800, 720/2, 90, 200, 200,600, 800));
  p2Units.push_back(new Unit(sf::String("Archer"),700, 360, 90, 200, 200,600, 800));
  p2Units.push_back(new Unit(sf::String("Archer"),1200, 360, 90, 200, 200,600, 800));
 
  //push tiles
  Tiles.push_back(new Tile(634,119));
  Tiles.push_back(new Tile(634,358));
  Tiles.push_back(new Tile(634,597)); //239 difference
  Tiles.push_back(new Tile(873,119));
  Tiles.push_back(new Tile(873,358));
  Tiles.push_back(new Tile(873,597)); //239 difference
  Tiles.push_back(new Tile(1112,119));
  Tiles.push_back(new Tile(1112,358));
  Tiles.push_back(new Tile(1112,597)); //239 difference

  while (running) {
    /******************v NECESSARY STUFF v*********************/
    sf::Event event;
    while (window.pollEvent(event)) {
      switch (event.type) {
      case sf::Event::Closed:
	window.close();
	break;
      case sf::Event::MouseButtonPressed:
	if (event.mouseButton.button == sf::Mouse::Left) {
	  gui.mousePressed = true;
	  //std::cout << "pressed" << std::endl;
	}
	break;
      case sf::Event::MouseButtonReleased:
	if (event.mouseButton.button == sf::Mouse::Left) {
	  gui.mousePressed = false;
	  //std::cout << "released" << std::endl;
	}
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

      //kill off units
      //this is really cheap and a huge potential memory leak, but it works for this scale
      for (unitIterator=p1Units.begin();unitIterator!=p1Units.end();++unitIterator) {
	if ((*unitIterator)->HPBar == 0) {
	  p1Units.erase(unitIterator);
	}
      }
      for (unitIterator=p2Units.begin();unitIterator!=p2Units.end();++unitIterator) {
	if ((*unitIterator)->HPBar == 0) {
	  p2Units.erase(unitIterator);
	}
      }

      //draws new stuff	
      //tiles first!!
      for (tileIterator=Tiles.begin();tileIterator!=Tiles.end();++tileIterator) {
	(*tileIterator)->step(window);
      }
      for (unitIterator=p1Units.begin();unitIterator!=p1Units.end();++unitIterator) {
	//window.draw((*unitIterator)->sprite);
	(*unitIterator)->step(window);
      }
      for (unitIterator=p2Units.begin();unitIterator!=p2Units.end();++unitIterator) {
	//window.draw((*unitIterator)->sprite);
	(*unitIterator)->step(window);
      }
      //step
      gui.step(window);
      game.step();

      
      //display new stuff
      window.display();
    }
  }
} //end gameLoop()

void loadAllTextures() {
  defaultUnitTexture.loadFromFile("defaultTexture.png");
  HPGreen.loadFromFile("HPGreen.png");
  HPRed.loadFromFile("HPRed.png");
  whiteTile.loadFromFile("whiteTile.png");
  redTile.loadFromFile("redTile.png");
  blueTile.loadFromFile("blueTile.png");
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
