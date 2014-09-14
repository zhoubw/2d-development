#include <SFML/Graphics.hpp>
#include "Projectile.hpp"
#include <iostream>
#include <sstream>
#include <math.h>

int toInt(float f) {
  if (f<0)
    return int(f-0.5);
  return int(f+0.5);
}


Projectile::Projectile(std::string source="blueBullet.png", int width=10, int height=11, int x_cor=1024/2, int y_cor=0, int heading=270, int speed=2) {

  this->source = source;
  this->texture.loadFromFile(source);
  this->sprite.setTexture(this->texture);

  this->width=width;
  this->height=height;
  this->heading=heading;
  this->headingRad=heading*3.14159/180;
  this->x=x_cor;
  this->y=y_cor;
  
  this->speed=speed;

  isAlive=true;

  sprite.setOrigin(width/2,height/2);
  //this->sprite.setPosition(x - width/2,y - height/2);
  sprite.setPosition(x,y);
  sprite.setRotation(heading * -1 + 90);
}

void Projectile::move(int x, int y) {
  //rotate according to angle
  sprite.setRotation(heading * -1 + 90);
  //moved so far per frame
  //could be useful later...
  int delta_x = 0;
  int delta_y = 0;

  if (x>0) {
    while (delta_x < x) {
      if (!hitPlayer(p)) {
	this->sprite.move(1,0);
	delta_x += 1;
	this->x += 1;
      }
      else {
	isAlive=false;
	break; //change bullet collision
      }
    }  
  }
  else {
    while (delta_x > x) {
      if (!hitPlayer(p)) {
        this->sprite.move(-1,0);
	delta_x -= 1;
	this->x -= 1;
      }
      else {
	isAlive=false;
	break; //change
      }
    }
  }
 
  if (y>0) {
    while (delta_y < y) {
      if (!hitPlayer(p)) {
	this->sprite.move(0,1);
	this->y += 1;
	delta_y += 1;
      }
      else {
	isAlive=false;
	break; //change
      }
    }
  }
  else {
    while (delta_y > y) {
      if (!hitPlayer(p)) {
	this->sprite.move(0,-1);
	this->y -= 1;
	delta_y -= 1;
      }
      else {
	isAlive=false;
	break; //change
      }
    }
  }
} //end Projectile::move()

void Projectile::step() {
  if (isAlive) {
    //move(int(speed*cos(heading*3.14159/180)), int(speed*sin(heading*3.14159/180)*-1));
    headingRad = heading*3.14159/180;
    move(toInt(speed*cos(headingRad)), toInt(speed*sin(headingRad)*-1));
  }
} //end Projectile::step()

bool Projectile::hitPlayer(Player p) {
  //<= might be worse than <
  if (( ( (x-p.x)*(x-p.x) ) / ( (width/2+p.width/2)*(width/2+p.width/2) ) + ( (y-p.y)*(y-p.y) ) / ( (height/2+p.height/2)*(height/2+p.height/2) ) ) < 1)
    return true;
  return false;
} //end Projectile::hitPlayer()

void Projectile::retexture() {
  texture.loadFromFile(source);
  sprite.setTexture(texture);
}
