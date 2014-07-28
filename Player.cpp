#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include "Player.hpp"
#include "MapGrid.hpp"
#include <iostream>
#include <sstream>

Player::Player(int x_cor=1024/2, int y_cor=768/2) {
  this->width=48;
  this->height=64;
  this->x = x_cor;
  this->y = y_cor;

  x1 = ((this->x-(this->width/2))-((this->x-(this->width/2)) % boxSize))/boxSize;
  x2 = (this->x - (this->x % boxSize))/boxSize;
  x3 = ((this->x+(this->width/2))-((this->x+(this->width/2)) % boxSize))/boxSize;
  
  y1 = ((this->y+(this->height/2))-((this->y+(this->height/2)) % boxSize))/boxSize;
  y2 = (this->y - (this->y % boxSize))/boxSize;
  y3 = ((this->y+(this->height/2))-((this->y+(this->height/2)) % boxSize))/boxSize;
  
  g = 3; //acceleration of gravity
  speed = 7;
  jumpSpeed = 25;
  dX = 0; //movement in X per frame
  dY = 0; //movement in Y per frame
  fallFrame = 0; //time value in vertical distance formula
  jumping = false;

  hp = 100; //actual hp
  maxHp = 100; //maximum hp
  hpBar = 100; //hp displayed on hp bar - want a smooth +/-

  //temporary shape for player
  shape = sf::RectangleShape(sf::Vector2f(width,height));
  shape.setPosition(this->x-(width/2),this->y-(height/2));
  shape.setFillColor(sf::Color::Green);
}


void Player::move(int x, int y) {
  //moved so far per frame
  //could be useful later...

  int delta_x = 0;
  int delta_y = 0;

  //temp for shape
  if (x>0) {
    while (delta_x < x) {
      if (!blockedRight()) {
	this->shape.move(1,0);
	delta_x += 1;
	this->x += 1;
      }
      else
	break;
    }  
  }
  else {
    while (delta_x > x) {
      if (!blockedLeft()) {
	this->shape.move(-1,0);
	delta_x -= 1;
	this->x -= 1;
      }
      else
	break;
    }
  }
 
  if (y>0) {
    while (delta_y < y) {
      this->shape.move(0,1);
      this->y += 1;
      delta_y += 1;
      if (grounded()) {
	jumping = false;
	break;
      }
    }
  }
  else {
    while (delta_y > y) {
      this->shape.move(0,-1);
      this->y -= 1;
      delta_y -= 1;
      if (capped()) {
	jumping = false;
	fallFrame = 0;
	break;
      }
    }
  }

}

void Player::fall() {
  //if not landed or !grounded()
  if (grounded()) {
    fallFrame = 0;
    dY = 0;
    if (jumping) {
      dY -= jumpSpeed;
    }
  }
  else {
    fallFrame += 1;
    dY = int((0.5 * g * fallFrame) + 0.5);
    if (jumping) {
      dY -= jumpSpeed;
    }
  }
}

void Player::jump() {
  if (grounded()) {
    jumping = true;
  }
}

bool Player::grounded() {
  //returns true if standing on block
  //WARNING: ONLY CALL WHEN FALLING
  //possible fix: check the point right on top of this one, it should not be in a block

  //convert the point on the block to the partition coordinate (starts right under feet of character)
  x2 = (this->x - (this->x % boxSize))/boxSize;
  y3  = ((this->y+(this->height/2))-((this->y+(this->height/2)) % boxSize))/boxSize;
  
  return isObstacle(x2, y3);
}

bool Player::capped() {
  //returns true if block is directly on top

  x2 = (this->x - (this->x % boxSize))/boxSize;
  y1 = ((this->y-(this->height/2))-((this->y-(this->height/2)) % boxSize))/boxSize;
  return isObstacle(x2, y1);
}


//these two are temporary. They need to be fixed.


bool Player::blockedLeft() {
  x1 = ((this->x-(this->width/2))-((this->x-(this->width/2)) % boxSize))/boxSize;
  //lower corner
  y3 = ((this->y+(this->height/2)-1)-((this->y+(this->height/2)-1) % boxSize))/boxSize;
  return isObstacle(x1, y3);
}

bool Player::blockedRight() {
  x3 = ((this->x+(this->width/2))-((this->x+(this->width/2)) % boxSize))/boxSize;
  y3 = ((this->y+(this->height/2)-1)-((this->y+(this->height/2)-1) % boxSize))/boxSize;
  return isObstacle(x3, y3);
}

//standard step per frame
void Player::step() {
  move(dX, dY);
}
