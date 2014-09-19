#ifndef UNIT_HPP
#define UNIT_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <iostream>

extern sf::Texture defaultUnitTexture;

class Unit {
public:
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
  int spriteCounter;
 
  Unit(int x, int y, int heading, int HP, int range, int power);
  
  void step(sf::RenderWindow& window);
  

};

#endif
