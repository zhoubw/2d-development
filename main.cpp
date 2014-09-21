#include "main.hpp"

sf::RenderWindow window(sf::VideoMode(1280, 720), "Subjugation v.0");
Gui gui(window);
Game game;

//Textures
sf::Texture defaultUnitTexture;
sf::Texture HPRed;
sf::Texture HPGreen;
sf::Texture whiteTile;
sf::Texture redTile;
sf::Texture blueTile;
sf::Texture p1Texture;
sf::Texture p2Texture;

//If game is running
bool running = false;

//init these somewhere else later
int totalFrame = 0;
sf::Time frameGap = sf::milliseconds(1000/60);


void gameLoop(sf::Clock clock, sf::Time frameGap) {

  loadAllTextures();
  //push units
  loadUnits();
  
  //push tiles
  loadTiles();
 
  while (running) {
    /******************v NECESSARY STUFF v*********************/
    sf::Event event;
    while (window.pollEvent(event)) {
      switch (event.type) {
      case sf::Event::Closed:
	window.close();
	break;
      case sf::Event::KeyPressed:
	if (event.key.code == sf::Keyboard::Space && game.currentPhase == 2) {
	  gui.spacePressed = true;
	}
	//case sf::Event::KeyReleased:
	//if (event.key.code == sf::Keyboard::Space) {
	//gui.spacePressed = false;
	//}
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
      for (int i=0;i<p1Units.size();i++) {
	if (p1Units.at(i)->HPBar == 0) {
	  p1Units.erase(p1Units.begin() + i);
	}
      }
      for (int i=0;i<p2Units.size();i++) {
	if (p2Units.at(i)->HPBar == 0) {
	  p2Units.erase(p2Units.begin() + i);
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
  p1Texture.loadFromFile("p1Texture.png");
  p2Texture.loadFromFile("p2Texture.png");
}

void loadUnits() {
  //all measurements are based on the first tile, top left corner

  //row1 p1
  p1Units.push_back(new Unit(true,sf::String("Footman"),570,55,90,100,100,35,60));
  p1Units.push_back(new Unit(true,sf::String("Footman"),698,55,90,100,100,35,60)); 
  p1Units.push_back(new Unit(true,sf::String("Footman"),570+240,55,90,100,100,35,60));
  p1Units.push_back(new Unit(true,sf::String("Footman"),698+240,55,90,100,100,35,60));
  p1Units.push_back(new Unit(true,sf::String("Footman"),570+240*2,55,90,100,100,35,60));
  p1Units.push_back(new Unit(true,sf::String("Footman"),698+240*2,55,90,100,100,35,60));
  
  //row2 p1
  p1Units.push_back(new Unit(true,sf::String("Footman"),570,55+240,90,100,100,35,60));
  p1Units.push_back(new Unit(true,sf::String("Footman"),698,55+240,90,100,100,35,60));
  p1Units.push_back(new Unit(true,sf::String("Archer"),873,55+240,90,100,100,200,40)); //single mid
  p1Units.push_back(new Unit(true,sf::String("Footman"),570+240*2,55+240,90,100,100,35,60));
  p1Units.push_back(new Unit(true,sf::String("Footman"),698+240*2,55+240,90,100,100,35,60));
  
  //row3 p1
  p1Units.push_back(new Unit(true,sf::String("Footman"),570,55+240*2,90,100,100,35,60));
  p1Units.push_back(new Unit(true,sf::String("Footman"),698,55+240*2,90,100,100,35,60));
  p1Units.push_back(new Unit(true,sf::String("Footman"),570+240,55+240*2,90,100,100,35,60));
  p1Units.push_back(new Unit(true,sf::String("Footman"),698+240,55+240*2,90,100,100,35,60));
  p1Units.push_back(new Unit(true,sf::String("Footman"),570+240*2,55+240*2,90,100,100,35,60));
  p1Units.push_back(new Unit(true,sf::String("Footman"),698+240*2,55+240*2,90,100,100,35,60));
  
  //row1 p2
  p2Units.push_back(new Unit(false,sf::String("Footman"),570,183,90,100,100,35,60));
  p2Units.push_back(new Unit(false,sf::String("Footman"),698,183,90,100,100,35,60)); 
  p2Units.push_back(new Unit(false,sf::String("Footman"),570+240,183,90,100,100,35,60));
  p2Units.push_back(new Unit(false,sf::String("Footman"),698+240,183,90,100,100,35,60));
  p2Units.push_back(new Unit(false,sf::String("Footman"),570+240*2,183,90,100,100,35,60));
  p2Units.push_back(new Unit(false,sf::String("Footman"),698+240*2,183,90,100,100,35,60));
  

  //row2 p2
  p2Units.push_back(new Unit(false,sf::String("Footman"),570,183+240,90,100,100,35,60));
  p2Units.push_back(new Unit(false,sf::String("Footman"),698,183+240,90,100,100,35,60));
  p2Units.push_back(new Unit(false,sf::String("Archer"),873,183+240,90,100,100,200,40)); //single mid
  p2Units.push_back(new Unit(false,sf::String("Footman"),570+240*2,183+240,90,100,100,35,60));
  p2Units.push_back(new Unit(false,sf::String("Footman"),698+240*2,183+240,90,100,100,35,60));
  
  //row3 p2
  p2Units.push_back(new Unit(false,sf::String("Footman"),570,183+240*2,90,100,100,35,60));
  p2Units.push_back(new Unit(false,sf::String("Footman"),698,183+240*2,90,100,100,35,60));
  p2Units.push_back(new Unit(false,sf::String("Footman"),570+240,183+240*2,90,100,100,35,60));
  p2Units.push_back(new Unit(false,sf::String("Footman"),698+240,183+240*2,90,100,100,35,60));
  p2Units.push_back(new Unit(false,sf::String("Footman"),570+240*2,183+240*2,90,100,100,35,60));
  p2Units.push_back(new Unit(false,sf::String("Footman"),698+240*2,183+240*2,90,100,100,35,60));

}

void loadTiles() {
 Tiles.push_back(new Tile(634,119));
 Tiles.push_back(new Tile(634,358));
 Tiles.push_back(new Tile(634,597)); //239 difference
 Tiles.push_back(new Tile(873,119));
 Tiles.push_back(new Tile(873,358));
 Tiles.push_back(new Tile(873,597)); //239 difference
 Tiles.push_back(new Tile(1112,119));
 Tiles.push_back(new Tile(1112,358));
 Tiles.push_back(new Tile(1112,597)); //239 difference
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
