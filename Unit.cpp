#include "Unit.hpp"

Unit::Unit(bool player, sf::String name, int x, int y, int heading, int HP, int moveRange, int attackRange, int power) {
  this->name = name;
  this->x = x;
  this->y = y;
  //might not even need to save this
  this->heading = heading;
  this->HP = HP;
  this->moveRange = moveRange;
  this->attackRange = attackRange;
  this->power = power;
  
  selected = false;
  ready = true;
  moved = false;
  attacked = false;
  isAlive = true;

  //let's aim for this to be default
  width = 32;
  height = 32;
  
  HPBar = HP;
  maxHP = HP;
  
  if (player) {
    //sprite.setTexture(defaultUnitTexture); //needs to be loaded!!
    sprite.setTexture(p1Texture);
  }
  else {
    sprite.setTexture(p2Texture);
  }
  sprite.setOrigin(width/2, height/2);
  sprite.setPosition(x, y);

  //probably all we need
  sprite.setRotation(heading);

  HPRedBar.setTexture(HPRed);
  HPRedBar.setOrigin(64/2, 10/2);
  HPRedBar.setPosition(x, y-32);
  HPGreenBar.setTexture(HPGreen);
  //HPGreenBar.setOrigin(64/2, 10/2);  
  HPGreenBar.setPosition(x-32, y-37);

  
}								   

//may not need this either
void Unit::step(sf::RenderWindow& window) {
  if (this->HPBar > HP) {
    HPBar--;
  }
  else if (this->HPBar < HP) {
    HPBar++;
  }
  if (HPBar <= 0) {
    //remove - check both vectors
  }
  HPRedBar.setPosition(x, y-32);
  //HPGreenBar.setPosition(x, y-32);
  HPGreenBar.setPosition(x-32, y-37);
  HPGreenBar.setScale(float(this->HPBar)/float(maxHP), 1);

  //sprite.setPosition(x,y);
  window.draw(sprite);
  window.draw(HPRedBar);
  window.draw(HPGreenBar);
  
}

void Unit::move(int targetX, int targetY) {
  //command to move to targeted position
  this->x = targetX;
  this->y = targetY;
  sprite.setPosition(targetX, targetY);
  moved = true;
}

void Unit::hit(Unit* unit) {
  unit->HP -= this->power;
  if (unit->HP < 0) {
    unit->HP = 0;
  }
  if (unit->HP == 0) {
    unit->isAlive = false;
  }
  attacked = true;
}

