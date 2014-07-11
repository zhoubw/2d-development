#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include "Player.hpp"
#include <iostream>
#include <sstream>

Player::Player(int x_cor=1024/2, int y_cor=768/2) {
  width=48;
  height=64;
  this->x = x_cor-(this->width/2);
  this->y = y_cor-(this->height/2);
  //let the floor = 200
  //gravity
  g = 1;
  speed = 7;
  dY=0;
  fallFrame=0;
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
      std::cout << this->y << " ";
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
  if (delta_y != y)
    fallFrame = 0;
}

void Player::fall() {
  //if not landed or !landed()
  if (y != 200 + height/2)
    fallFrame += 1;
  dY = int(0.5 * g * fallFrame); //maybe + 0.5
  move(0, dY);
}
