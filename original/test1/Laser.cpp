#include "Laser.hpp"
#include <iostream>
#include <math.h>

Laser::Laser(std::string source="laser.png", int width=10, int height=50, int x_cor=1024/2, int y_cor=0, int heading=270, int speed=10)
  :Projectile(source,width,height,x_cor,y_cor,heading,speed) {

  /*
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
  */
  reflected = false;
}

void Laser::move(int x, int y) {
  sprite.setRotation(heading * -1 + 90);

  int delta_x = 0;
  int delta_y = 0;

  if (x>0) {
    while (delta_x < x) {
      if (hitMirror(mirror) && !reflected) {

	//change direction******
	//heading = int( ( atan2( mirror.y-y, x-mirror.x ) * 180 ) / 3.14159);
	heading -= 180;
	if (heading < 0) heading += 360;


	heading -= 2 * (heading - mirror.heading);
	if (heading < 0) heading += 360;

	reflected = true;
      }
            
      if (!hitPlayer(p)) {
	this->sprite.move(1,0);
	delta_x += 1;
	this->x += 1;
      }
      else {
	isAlive = false;
	break;
      }
    }
  }
  else {
    while (delta_x > x) {
      //mirror
      if (hitMirror(mirror) && !reflected) {
	
	//change direction******
	//heading = int( ( atan2( mirror.y-y, x-mirror.x ) * 180 ) / 3.14159);
	heading -= 180;
	if (heading < 0) heading += 360;
	
	heading -= 2 * (heading - mirror.heading);
	if (heading < 0) heading += 360;
	
	reflected = true;
      }
      
      if (!hitPlayer(p)) {
	this->sprite.move(-1,0);
	delta_x -= 1;
	this->x -= 1;
      }
      else {
	isAlive = false;
	break;
      }
    }
  }
  
  if (y>0) {
    while (delta_y < y) {
      //mirror
      if (hitMirror(mirror) && !reflected) {
	
	//change direction******
	//heading = int( ( atan2( mirror.y-y, x-mirror.x ) * 180 ) / 3.14159);
	heading -= 180;
	if (heading < 0) heading += 360;
	
	heading -= 2 * (heading - mirror.heading);
	if (heading < 0) heading += 360;
	
	reflected = true;
      }

      if (!hitPlayer(p)) {
	this->sprite.move(0,1);
	this->y += 1;
	delta_y += 1;
      }
      else {
	isAlive = false;
	break;
      }
    }
  }
  else {
    while (delta_y > y) {
      //mirror
      if (hitMirror(mirror) && !reflected) {
	
	//change direction******
	//heading = int( ( atan2( mirror.y-y, x-mirror.x ) * 180 ) / 3.14159);
	heading -= 180;
	if (heading < 0) heading += 360;
	
	heading -= 2 * (heading - mirror.heading);
	if (heading < 0) heading += 360;
	
	reflected = true;
      }
      
      if (!hitPlayer(p)) {
	this->sprite.move(0,-1);
	this->y -= 1;
	delta_y -= 1;
      }
      else {
	isAlive = false;
	break;	
      }
    }
  }

} //end Laser::move()

bool Laser::hitMirror(Mirror mirror) {
  if (( ( (x-mirror.x)*(x-mirror.x) ) / ( (width/2+mirror.width/2)*(width/2+mirror.width/2) ) + ( (y-mirror.y)*(y-mirror.y) ) / ( (height/2+mirror.height/2)*(height/2+mirror.height/2) ) ) < 1)
    
    return true;
  return false;
} //end Laser::hitMirror()
