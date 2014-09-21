#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/String.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include "Unit.hpp"
#include "Tile.hpp"

class Gui;

extern std::vector<Unit*> p1Units;
extern std::vector<Unit*> p2Units;
extern std::vector<Unit*>::iterator unitIterator;
extern std::vector<Tile*> Tiles;
extern std::vector<Tile*>::iterator tileIterator;

extern Gui gui;

class Game {
public:
  Unit* currentUnit;
  Tile* currentTile;
  int currentPhase;
  bool currentPlayer; //true is 1, false is 2
  bool playing;
  //Gui& gui;
  
  Game();
  bool checkAllMoved(std::vector<Unit*>& Units);
  void resetUnits(std::vector<Unit*>& Units);
  bool checkValidMoveTarget();
  Unit* checkValidAttackTarget();
  void step();
  void checkWin();
};

#endif
