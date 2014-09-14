#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "Unit.hpp"

extern sf::Texture playerTexture;

class Player: public Unit {
public:
  unsigned int HP;
  unsigned int maxHP;
  unsigned int HPBar;

  Player(int x, int y);
  void step(sf::RenderWindow& window);
};

#endif
