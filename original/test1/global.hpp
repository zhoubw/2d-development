//#include "main.hpp"
//#include "Mirror.hpp" //includes Projectile
//#include "Projectile.hpp" //includes Player
//#include "Player.hpp"

#ifndef GLOBAL_HPP
#define GLOBAL_HPP
#include "Mirror.hpp"
#include "Projectile.hpp"
const int width = 1280;
const int height = 720;

Player p(width/2, height/2);
Mirror mirror(p);
Projectile prj("blueBullet.png", 13,13,1024/2,0,270,2);
#endif
