#include "Gui.hpp" //includes Game.hpp

//Collections and iterators
std::vector<Unit*> p1Units;
std::vector<Unit*> p2Units;
std::vector<Unit*>::iterator unitIterator;
std::vector<Tile*> Tiles;
std::vector<Tile*>::iterator tileIterator;

Game::Game() {
  currentUnit = NULL;
  currentTile = NULL;
  currentPhase = 0;
  currentPlayer = true;
  illegalMove = false;
  playing = true;
}

void Game::step() {
  //check to see if Units can be reset
  if (currentPlayer) {
    resetUnits(p1Units);
      }
  else {
    resetUnits(p2Units);
  }
  checkWin();
  if (playing) {
    switch (currentPhase) {
    case 0:
      //change status message
      gui.status = "Start of turn for ";
      if (currentPlayer) {
	gui.status.append(std::string("Player 1. Select a ready unit."));
      }
      else {
	gui.status.append(std::string("Player 2. Select a ready unit."));
      }
      //selects the Unit for the turn
      if (gui.mousePressed) {
	  currentUnit = gui.selectedUnit;
	  if (currentUnit != NULL) {
	    if (!currentUnit->ready) {
	      currentUnit = NULL;
	    }
	  }
	  currentTile = gui.selectedTile;
      }
      else {
	if (currentUnit != NULL) {
	  currentPhase++;
	}
      }
      break;
  
    case 1:
      gui.status = "Move unit; skip your battle if you cross the box.";
      if (gui.mousePressed) {
	if (checkValidMoveTarget()) {
	  //move the unit and advance phase
	  currentUnit->move(gui.mouseX, gui.mouseY);
	}
	else {
	  //illegal move skips battle
	  currentUnit->move(gui.mouseX, gui.mouseY);
	  illegalMove = true;
	}
	//std::cout << sf::Mouse::isButtonPressed(sf::Mouse::Left) << std::endl;
      }
      else {
	if (currentUnit->moved) {
	  currentPhase++;
	  if (illegalMove) {
	    illegalMove = false;
	    currentPhase++;
	  }
	  currentUnit->moved = false;
	}
      }
      break;
    case 2:
      gui.status = "Select attack target-click in range (skip w/Space)";
      if (gui.spacePressed && !currentUnit->attacked) {
	currentPhase++;
	gui.spacePressed = false;
      }

      if (gui.mousePressed) {
	if (checkValidAttackTarget() != NULL && !currentUnit->attacked) {
	  gui.selectedUnit = NULL;      
	  currentUnit->hit(checkValidAttackTarget());
	}
      }
      else {
	if (currentUnit->attacked) {
	  currentPhase++;
	  currentUnit->attacked = false;
	}
      }
      break;
    case 3:
      gui.status = "End Phase. Left-click anywhere to continue.";
      currentUnit->ready = false;
      if (gui.mousePressed) {
	currentUnit = NULL;
	gui.selectedUnit = NULL;
	currentPhase = 0;
	currentPlayer = !currentPlayer;
      }
      break;
    }//end switch 
  }

}

bool Game::checkAllMoved(std::vector<Unit*>& Units) {
  for (unitIterator=Units.begin();unitIterator!=Units.end();++unitIterator) {
    if ((*unitIterator)->ready) {
      return false;
    }
  }
  return true;
}

void Game::resetUnits(std::vector<Unit*>& Units) {
  if (checkAllMoved(Units)) {
    for (unitIterator=Units.begin();unitIterator!=Units.end();++unitIterator) {
      (*unitIterator)->ready = true;
    }
  }
}

bool Game::checkValidMoveTarget() {
  //  if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
  if (gui.mousePressed) {
    if (currentTile->sprites.at(currentTile->id).getGlobalBounds().contains(gui.mouseX, gui.mouseY) &&
	((currentUnit->x-gui.mouseX)*(currentUnit->x-gui.mouseX)) + ((currentUnit->y-gui.mouseY)*(currentUnit->y-gui.mouseY)) <= ((currentUnit->moveRange)*(currentUnit->moveRange))) {
      return true;
    }
  }
  return false;
}

Unit* Game::checkValidAttackTarget() {
  //  if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
  if (gui.mousePressed) {  
    if (currentPlayer) { //loop through enemy's units
      for (unitIterator=p2Units.begin();unitIterator!=p2Units.end();++unitIterator) { //loop
	if ((*unitIterator)->sprite.getGlobalBounds().contains(gui.mouseX,gui.mouseY)) { //found a unit
	  if (((currentUnit->x-gui.mouseX)*(currentUnit->x-gui.mouseX)) + ((currentUnit->y-gui.mouseY)*(currentUnit->y-gui.mouseY)) <= ((currentUnit->attackRange)*(currentUnit->attackRange))) {
	    return (*unitIterator);
	  }
	}
      }
    }
    else {
      for (unitIterator=p1Units.begin();unitIterator!=p1Units.end();++unitIterator) { //loop
	if ((*unitIterator)->sprite.getGlobalBounds().contains(gui.mouseX,gui.mouseY)) { //found a unit
	  if (((currentUnit->x-gui.mouseX)*(currentUnit->x-gui.mouseX)) + ((currentUnit->y-gui.mouseY)*(currentUnit->y-gui.mouseY)) <= ((currentUnit->attackRange)*(currentUnit->attackRange))) {
	    return (*unitIterator);
	  }
	}
      }
    }
  }
  //return false;
  return NULL;
}

void Game::checkWin() {
  //std::cout << Tiles.at(1)->id << std::endl;
  //std::cout << Tiles.at(4)->id << std::endl;
  //std::cout << Tiles.at(7)->id << std::endl;
  if (p1Units.empty()) {
    playing = false;
    gui.status = "Player 1's units have been annihilated. Player 2 wins.";
  }
  if (p2Units.empty()) {
    playing = false;
    gui.status = "Player 2's units have been annihilated. Player 1 wins.";
  }
  //I really screwed up here, I should have made 2d vectors but that would screw everything over. meh
  if ((Tiles.at(0)->id==Tiles.at(1)->id&&Tiles.at(1)->id==Tiles.at(2)->id) ||
      (Tiles.at(0)->id==Tiles.at(3)->id&&Tiles.at(3)->id==Tiles.at(6)->id)) {
    if (Tiles.at(0)->id == 1) {
      playing = false;
      gui.status = "Player 1 captured 3 in a row. Player 1 wins.";
    }
    else if (Tiles.at(0)->id == 2){
      playing = false;
      gui.status = "Player 2 captured 3 in a row. Player 2 wins.";
    }
  } //012,036
  if ((Tiles.at(8)->id==Tiles.at(5)->id&&Tiles.at(5)->id==Tiles.at(2)->id) ||
	   (Tiles.at(8)->id==Tiles.at(7)->id&&Tiles.at(7)->id==Tiles.at(6)->id)) {
    if (Tiles.at(8)->id == 1) {
      playing = false;
      gui.status = "Player 1 captured 3 in a row. Player 1 wins.";
    }
    else if (Tiles.at(8)->id == 2) {
      playing = false;
      gui.status = "Player 2 captured 3 in a row. Player 2 wins.";
    }
  } //876,852
  if (((Tiles.at(3)->id==Tiles.at(4)->id&&Tiles.at(4)->id==Tiles.at(5)->id) ||
	    (Tiles.at(1)->id==Tiles.at(4)->id&&Tiles.at(4)->id==Tiles.at(7)->id)) ||
	   ((Tiles.at(0)->id==Tiles.at(4)->id&&Tiles.at(4)->id==Tiles.at(8)->id) ||
	    (Tiles.at(2)->id==Tiles.at(4)->id&&Tiles.at(4)->id==Tiles.at(6)->id))) {
    if (Tiles.at(4)->id == 1) {
      playing = false;
      gui.status = "Player 1 captured 3 in a row. Player 1 wins.";
    }
    else if (Tiles.at(4)->id == 2) {
      playing = false;
      gui.status = "Player 2 captured 3 in a row. Player 2 wins.";
    }
  } //345, 147, 048, 246
    
    //}//end 3 checks
}
