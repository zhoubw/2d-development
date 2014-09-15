#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include <math.h>
#include "Player.hpp"
#include "Projectile.hpp"

extern b2Vec2 gravity;
extern b2World world;

//In Box2D, 1 meter = 30 px
extern const float SCALE = 30.f;

const int WIDTH = 1280;
const int HEIGHT = 720;
const float FPS = 60.f;

bool KEY_W;
bool KEY_A;
bool KEY_S;
bool KEY_D;

void gameLoop();

std::vector<Projectile*> Projectiles;
std::vector<Projectile*>::iterator prjIterator;

//textures
extern sf::Texture playerTexture;
extern sf::Texture blueBulletTexture;


#endif
