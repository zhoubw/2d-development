#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include "Player.hpp"
#include "MapGrid.hpp"
#include <iostream>
#include <sstream>

Player::Player(int x_cor=1024/2, int y_cor=768/2) {
  this->width=48;
  this->height=64;
  this->x = x_cor-(this->width/2);
  this->y = y_cor-(this->height/2);
  //let the floor = 200
  //gravity
  g = 3;
  speed = 7;
  jumpSpeed = 25;
  dY=0;
  fallFrame=0;
  jumping = false;
  shape = sf::RectangleShape(sf::Vector2f(width,height));
  shape.setPosition(this->x,this->y);
  shape.setFillColor(sf::Color::Green);
}


void Player::move(int x, int y) {
  //moved so far per frame
  int delta_x = 0;
  int delta_y = 0;
  bool isNegX = x<0;
  bool isNegY = y<0;
  
  //temp for shape
  if (!isNegX) {
    while (delta_x < x) {
      //check obstacle
      this->shape.move(1,0);
      delta_x += 1;
    }  
  }
  else {
    while (delta_x > x) {
      //check obstacle
      this->shape.move(-1,0);
      delta_x -= 1;
    }
  }
  this->x += delta_x;
 
  if (!isNegY) {
    while (delta_y < y) {
      //check obstacle
      if (this->y + delta_y == 200) {
	break;
      }
      this->shape.move(0,1);
      delta_y += 1;
      
    }  
  }
  else {
    while (delta_y > y) {
      //check obstacle
      this->shape.move(0,-1);
      delta_y -= 1;
    }
  }
  this->y += delta_y;
  //again, temporary.
  if (delta_y != y) {
    fallFrame = 0;
    jumping = false;
  }
}

void Player::fall() {
  //if not landed or !grounded()
  if (y != 200 + height/2)
    fallFrame += 1;
  dY = int(0.5 * g * fallFrame); //maybe + 0.5
  if (jumping) {
    dY -= jumpSpeed;
  }
  move(0, dY);
}

void Player::jump() {
    jumping = true;
}

bool Player::grounded() {
  //returns true if standing on block
  //WARNING: ONLY CALL WHEN FALLING
  //possible fix: check the point right on top of this one, it should not be in a block
  //convert the point on the block to the partition coordinate.
  int xBox = (x - (x % boxSize))/boxSize;
  int yBox = (((y+this->height/2)+1) - ((y+this->height/2+1) % boxSize))/boxSize;
  if (map[xBox][yBox] > 0)
    return true;
  return false;
  
}