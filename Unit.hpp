#ifndef UNIT_HPP
#define UNIT_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <iostream>

extern sf::Texture defaultUnitTexture;
extern sf::Texture HPRed;
extern sf::Texture HPGreen;
extern sf::Texture p1Texture;
extern sf::Texture p2Texture;
class Unit {
public:
  sf::String name;
  int width, height;
  int HP;
  int HPBar;
  int maxHP;
  
  int x, y, heading;

  int attackRange;
  int moveRange;
  int power;

  bool selected;
  bool ready;
  bool moved;
  bool attacked;
  bool isAlive;

  sf::Sprite sprite;
  sf::Sprite HPRedBar;
  sf::Sprite HPGreenBar;

  Unit(bool player, sf::String name,int x, int y, int heading, int HP, int moveRange,int attackRange, int power);
  
  void step(sf::RenderWindow& window);
  void move(int targetX, int targetY);
  void hit(Unit* unit);
};

extern std::vector<Unit*> p1Units;
extern std::vector<Unit*> p2Units;
extern std::vector<Unit*>::iterator unitIterator;

#endif
