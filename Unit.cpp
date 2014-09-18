#include "Unit.hpp"

Unit::Unit(int x, int y, int heading, int HP, int range, int power) {
  this->x = x;
  this->y = y;
  this->heading = heading;
  this->HP = HP;
  this->range = range;
  this->power = power;
  
  //let's aim for this to be default
  width = 24;
  height = 24;
  
  HPBar = HP;
  maxHP = HP;
  
  sprite.setTexture(defaultUnitTexture); //needs to be loaded!!
  sprite.setPosition(x, y);
  sprite.setOrigin(width/2, height/2);
  sprite.setRotation(
  

}								   
