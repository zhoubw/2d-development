#ifndef GUI_HPP
#define GUI_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/String.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include "Unit.hpp"

extern std::vector<Unit*> Units;
extern std::vector<Unit*>::iterator unitIterator;

class Gui {
public:
  int mouseX, mouseY;
  
  Unit* hoveredUnit;
  Unit* selectedUnit;

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
  void checkMouse(sf::RenderWindow& window);
  bool mouseIsHovering(Unit* unit);
  bool isClickingUnit(Unit* unit);
  bool updateUnit();
  
};

#endif
