#include "Unit.hpp"

Unit::Unit(int x, int y, int heading, int HP, int range, int power) {
  this->x = x;
  this->y = y;
  //might not even need to save this
  this->heading = heading;
  this->HP = HP;
  this->range = range;
  this->power = power;
  
  selected = false;
  ready = true;

  //let's aim for this to be default
  width = 24;
  height = 24;
  
  HPBar = HP;
  maxHP = HP;
  
  sprite.setTexture(defaultUnitTexture); //needs to be loaded!!
  sprite.setPosition(x, y);
  sprite.setOrigin(width/2, height/2);
  //probably all we need
  sprite.setRotation(heading);

  //don't need this until much, much later
  spriteCounter = 0;

}								   

//may not need this either
void step(sf::RenderWindow& window) {
  
  
}
