#ifndef MAIN_HPP
#define MAIN_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <iostream>

extern sf::RenderWindow window;

/*** Textures ***/
extern sf::Texture defaultUnitTexture;


void gameLoop();
void loadAllTextures();
#endif
