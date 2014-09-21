#ifndef MAIN_HPP
#define MAIN_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <iostream>
#include "Unit.hpp"
#include "Gui.hpp"
#include "Game.hpp"
#include "Tile.hpp"

extern sf::RenderWindow window;
extern Game game;
extern Gui gui;

/*** Textures ***/
extern sf::Texture defaultUnitTexture;
extern sf::Texture HPRed;
extern sf::Texture HPGreen;
extern sf::Texture whiteTile;
extern sf::Texture redTile;
extern sf::Texture blueTile;

extern std::vector<Unit*> p1Units;
extern std::vector<Unit*> p2Units;
extern std::vector<Unit*>::iterator unitIterator;
extern std::vector<Tile*> Tiles;
extern std::vector<Tile*>::iterator tileIterator;

//Shall I make a game class?
void gameLoop();
void loadAllTextures();

#endif
