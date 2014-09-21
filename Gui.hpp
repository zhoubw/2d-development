#ifndef GUI_HPP
#define GUI_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/String.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include "Unit.hpp"
#include "Game.hpp"
#include "Tile.hpp"

extern std::vector<Unit*> p1Units;
extern std::vector<Unit*> p2Units;
extern std::vector<Unit*>::iterator unitIterator;
extern Game game;
extern std::vector<Tile*> Tiles;
extern std::vector<Tile*>::iterator tileIterator;


class Gui {
public:
  int mouseX, mouseY;
  bool mousePressed;
  
  Unit* hoveredUnit;
  Unit* selectedUnit;
  Tile* selectedTile;

  std::string status;
  std::string unitName;
  std::string positionString;
  std::string HPString;
  std::string powerString;
  std::string rangeString;
  std::string readyString;
  sf::Font font;
  sf::Text statusT;
  sf::Text unitNameT;
  sf::Text positionStringT;
  sf::Text HPStringT;
  sf::Text powerStringT;
  sf::Text rangeStringT;
  sf::Text readyStringT;
  
  
  
  sf::CircleShape rangeCircle;

  Gui(sf::RenderWindow& window);
  void step(sf::RenderWindow& window);
  void drawTexts(sf::RenderWindow& window);
  void drawRangeCircle(sf::RenderWindow& window);
  void checkMouse(sf::RenderWindow& window, std::vector<Unit*>& Units);
  bool mouseIsHovering(Unit* unit);
  bool isClickingUnit(Unit* unit);
  bool mouseIsHovering(Tile* tile);
  bool isClickingTile(Tile* tile);
  bool updateUnit();
  
};

#endif
