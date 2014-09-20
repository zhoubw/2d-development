#ifndef MAIN_HPP
#define MAIN_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <iostream>
#include "Unit.hpp"
#include "Gui.hpp"

extern sf::RenderWindow window;

/*** Textures ***/
extern sf::Texture defaultUnitTexture;
extern sf::Texture HPRed;
extern sf::Texture HPGreen;

extern std::vector<Unit*> Units;
extern std::vector<Unit*>::iterator unitIterator;


//Shall I make a game class?
void gameLoop();
void loadAllTextures();

#endif
