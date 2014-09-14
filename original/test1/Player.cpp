#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include "Player.hpp"
#include <iostream>
#include <sstream>

Player::Player(int x_cor=1280/2, int y_cor=720/2) {
  this->width=48;
  this->height=48;
  this->x = x_cor;
  this->y = y_cor;
  
  speed = 3;
  dX = 0; //movement in X per frame
  dY = 0; //movement in Y per frame

  hp = 100; //actual hp
  maxHp = 100; //maximum hp
  hpBar = 100; //hp displayed on hp bar - want a smooth +/-

  hpTxt.loadFromFile("hpbar3.png");
  hpSprite.setTexture(hpTxt);
  hpSprite.setPosition(0,0);

  //temporary shape for player
  shape.setRadius(this->width/2);
  shape.setFillColor(sf::Color::Green);
  shape.setOutlineColor(sf::Color::Red);
  shape.setOutlineThickness(4);
  shape.setPosition(this->x-(this->width/2),this->y-(this->height/2));
}


void Player::move(int x, int y) {
  //moved so far per frame
  //could be useful later...

  int delta_x = 0;
  int delta_y = 0;

  //temp for shape
  if (x>0) {
    while (delta_x < x) {
      //if (!blockedRight()) {
	this->shape.move(1,0);
	delta_x += 1;
	this->x += 1;
	//}
	//else
	//break;
    }  
  }
  else {
    while (delta_x > x) {
      //if (!blockedLeft()) {
        this->shape.move(-1,0);
	delta_x -= 1;
	this->x -= 1;
	//}
	//else
	//break;
    }
  }
 
  if (y>0) {
    while (delta_y < y) {
      this->shape.move(0,1);
      this->y += 1;
      delta_y += 1;
      //if (grounded()) {
      //jumping = false;
      //break;
      //}
    }
  }
  else {
    while (delta_y > y) {
      this->shape.move(0,-1);
      this->y -= 1;
      delta_y -= 1;
      //if (capped()) {
      //jumping = false;
      //fallFrame = 0;
      //break;
      //}
    }
  }

} //end Player::move()

//standard step per frame
void Player::step() {
  move(dX, dY);
} //end Player::step()
