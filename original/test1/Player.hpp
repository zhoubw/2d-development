//Header file for Player
#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>

class Player {
public: 
  
  int x, y;
  int speed, dX, dY;
  int width;
  int height;

  int hp;
  int maxHp;
  int hpBar;
  
  sf::Texture texture;
  sf::Sprite sprite;
  //temp
  //sf::RectangleShape shape;
  sf::CircleShape shape;

  sf::Texture hpTxt;
  sf::Sprite hpSprite;

  void move(int x,int y);
  void step();
  Player(int,int);
};

#endif
