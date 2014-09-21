#ifndef TILE_HPP
#define TILE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include "Unit.hpp"

//extern 3 colors
extern sf::Texture whiteTile;
extern sf::Texture redTile;
extern sf::Texture blueTile;

extern std::vector<Unit*> p1Units;
extern std::vector<Unit*> p2Units;
extern std::vector<Unit*>::iterator unitIterator;

class Tile {
public:
  int id; //0, 1, or 2
  int x, y;
  std::vector<sf::Sprite> sprites;
  
  Tile(int x, int y);
  void step(sf::RenderWindow& window);
  int containedSpritesp1();
  int containedSpritesp2();
};

#endif
