#include "Unit.hpp"

Unit::Unit(sf::String name, int x, int y, int heading, int HP, int range, int power) {
  this->name = name;
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
  width = 32;
  height = 32;
  
  HPBar = HP;
  maxHP = HP;
  
  sprite.setTexture(defaultUnitTexture); //needs to be loaded!!
  sprite.setOrigin(width/2, height/2);
  sprite.setPosition(x, y);

  //probably all we need
  sprite.setRotation(heading);

  HPRedBar.setTexture(HPRed);
  HPRedBar.setOrigin(64/2, 10/2);
  HPRedBar.setPosition(x, y-32);
  HPGreenBar.setTexture(HPGreen);
  HPGreenBar.setOrigin(64/2, 10/2);  
  HPGreenBar.setPosition(x, y-32);

  //don't need this until much, much later
  spriteCounter = 0;

}								   

//may not need this either
void Unit::step(sf::RenderWindow& window) {
  if (this->HPBar > HP) {
    HPBar--;
  }
  else if (this->HPBar < HP) {
    HPBar++;
  }
  HPRedBar.setPosition(x, y-32);
  HPGreenBar.setPosition(x, y-32);
  HPGreenBar.setScale(float(this->HPBar)/float(maxHP), 1);

  window.draw(sprite);
  window.draw(HPRedBar);
  window.draw(HPGreenBar);
  
}
