#ifndef UNIT_HPP
#define UNIT_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <iostream>

extern sf::Texture defaultUnitTexture;
extern sf::Texture HPRed;
extern sf::Texture HPGreen;

class Unit {
public:
  sf::String name;
  int width, height;
  unsigned int HP;
  unsigned int HPBar;
  unsigned int maxHP;
  
  int x, y, heading;

  int range;
  int power;

  bool selected;
  bool ready;
  
  sf::Sprite sprite;
  sf::Sprite HPRedBar;
  sf::Sprite HPGreenBar;

  int spriteCounter;
 
  Unit(sf::String name,int x, int y, int heading, int HP, int range, int power);
  
  void step(sf::RenderWindow& window);

};

#endif
