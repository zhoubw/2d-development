#ifndef MIRROR_HPP
#define MIRROR_HPP
#include "Player.hpp"

class Mirror {
public:
  int x, y; //center of mirror
  int mouseX, mouseY;
  int heading;
  int width;
  int height;

  sf::Texture texture;
  sf::Sprite sprite;
  Mirror(Player p);

  void step(Player p, int mouseX, int mouseY);
};
#endif
