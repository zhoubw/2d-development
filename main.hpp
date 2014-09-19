#ifndef MAIN_HPP
#define MAIN_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <iostream>

extern sf::RenderWindow window;

/*** Textures ***/
extern sf::Texture defaultUnitTexture;

std::vector<Unit*> Units;
std::vector<Unit*>::iterator unitIterator;


//Shall I make a game class?
void gameLoop();
void loadAllTextures();

#endif
