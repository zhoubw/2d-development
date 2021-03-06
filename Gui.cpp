#include "Gui.hpp"

std::string toString(int n) {
  std::stringstream ss;
  ss << n;
  return std::string(ss.str());
}

Gui::Gui(sf::RenderWindow& window) {
  mouseX = sf::Mouse::getPosition(window).x;
  mouseY = sf::Mouse::getPosition(window).y;
  mousePressed = false;
  spacePressed = false;

  hoveredUnit = NULL;
  selectedUnit = NULL;
  selectedTile = NULL;
  status = "Testing phase";
  unitName = "None selected";
  positionString = "Position:";
  HPString = "HP:";
  powerString = "Power:";
  rangeString = "Range:";
  readyString = "Ready? :";
  font.loadFromFile("SAOFont.ttf");
  statusT.setFont(font); //default 30 size
  statusT.setString(status);
  statusT.setPosition(2,688);
  unitNameT.setFont(font);
  unitNameT.setString(unitName);
  unitNameT.setPosition(2,2);
  positionStringT.setFont(font);
  positionStringT.setString(positionString);
  positionStringT.setPosition(2,34);
  HPStringT.setFont(font);
  HPStringT.setString(HPString);
  HPStringT.setPosition(2,66);
  powerStringT.setFont(font);
  powerStringT.setString(powerString);
  powerStringT.setPosition(2,98);
  rangeStringT.setFont(font);
  rangeStringT.setString(rangeString);
  rangeStringT.setPosition(2,130);
  readyStringT.setFont(font);
  readyStringT.setString(readyString);
  readyStringT.setPosition(2,162);

  rangeCircle.setOutlineThickness(5);
  rangeCircle.setOutlineColor(sf::Color(0,255,255));
  rangeCircle.setFillColor(sf::Color::Transparent);
  rangeCircle.setOrigin(rangeCircle.getRadius(), rangeCircle.getRadius());
  rangeCircle.setRadius(0);
  rangeCircle.setPosition(0,0);
  
}

void Gui::step(sf::RenderWindow& window) {

  //rechecks mouse position
  mouseX = sf::Mouse::getPosition(window).x;
  mouseY = sf::Mouse::getPosition(window).y;
  if (game.currentPlayer) {
    checkMouse(window, p1Units);
  }
  else {
    checkMouse(window, p2Units);
  }
  drawTexts(window);
  drawRangeCircle(window);
}

void Gui::drawTexts(sf::RenderWindow& window) {
  //need to update texts!
  statusT.setString(status);
  unitNameT.setString(unitName);
  positionStringT.setString(positionString);
  HPStringT.setString(HPString);
  powerStringT.setString(powerString);
  rangeStringT.setString(rangeString);
  readyStringT.setString(readyString);

  window.draw(statusT);
  window.draw(unitNameT);
  window.draw(positionStringT);
  window.draw(HPStringT);
  window.draw(powerStringT);
  window.draw(rangeStringT);
  window.draw(readyStringT);
}

void Gui::drawRangeCircle(sf::RenderWindow& window) {
  if (selectedUnit != NULL) {
    if (game.currentPhase < 2) { // 2 is battle phase
      rangeCircle.setRadius(selectedUnit->moveRange);
    }
    else {
      rangeCircle.setRadius(selectedUnit->attackRange);
    }
    rangeCircle.setOrigin(rangeCircle.getRadius(), rangeCircle.getRadius());
    rangeCircle.setPosition(selectedUnit->x, selectedUnit->y);

    window.draw(rangeCircle);
  }
  else if (hoveredUnit != NULL) {
    if (game.currentPhase < 2) { // 2 is battle phase
      rangeCircle.setRadius(hoveredUnit->moveRange);
    }
    else {
      rangeCircle.setRadius(hoveredUnit->attackRange);
    }
    rangeCircle.setOrigin(rangeCircle.getRadius(), rangeCircle.getRadius());
    rangeCircle.setPosition(hoveredUnit->x, hoveredUnit->y);

    window.draw(rangeCircle);
  }
}

void Gui::checkMouse(sf::RenderWindow& window, std::vector<Unit*>& Units) {
  //checks if mouse is hovering over a unit
  for (unitIterator=Units.begin();unitIterator!=Units.end();++unitIterator) {
    if (mouseIsHovering((*unitIterator))) {
      //std::cout << "hovering" << std::endl;
      if (selectedUnit == NULL || hoveredUnit != selectedUnit) {
	hoveredUnit = (*unitIterator);
	//to use "updateUnit()"
	updateUnit();
      }
      if (isClickingUnit((*unitIterator))) {
	selectedUnit = (*unitIterator);
	for (tileIterator=Tiles.begin();tileIterator!=Tiles.end();++tileIterator) {
	  if (isClickingTile((*tileIterator))) {
	    selectedTile = (*tileIterator);
	    //std::cout << selectedTile << std::endl;
	  }
	}
      }
      //break out of hovering
      break;
    }
    else {
      //if (hoveredUnit != NULL) {
      //if (hoveredUnit != selectedUnit) {
      //hoveredUnit = NULL;
      //}
      hoveredUnit = NULL;
    }
    updateUnit();
  }
  if (hoveredUnit == NULL && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
    selectedUnit = NULL;
    selectedTile = NULL; //might not work
  } //end for loop
    /*
      std::cout << unitName << std::endl;
      std::cout << positionString << std::endl;
      std::cout << HPString << std::endl;
      std::cout << powerString << std::endl;
      std::cout << rangeString << std::endl;
      std::cout << readyString << std::endl;
    */
  //std::cout << hoveredUnit << std::endl;
  //std::cout << selectedUnit << std::endl; 

}
bool Gui::mouseIsHovering(Unit* unit) {
  return (unit->sprite.getGlobalBounds().contains(mouseX,mouseY));
}
bool Gui::isClickingUnit(Unit* unit) {
  return mouseIsHovering(unit) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
}
bool Gui::mouseIsHovering(Tile* tile) {
  return (tile->sprites.at(tile->id).getGlobalBounds().contains(mouseX,mouseY));
}
bool Gui::isClickingTile(Tile* tile) {
  return mouseIsHovering(tile) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

bool Gui::updateUnit() {
  if (hoveredUnit==NULL && selectedUnit==NULL) {
    unitName = "None selected";
    positionString = "Position:";
    HPString = "HP:";
    powerString = "Power:";
    rangeString = "Range:";
    readyString = "Ready? :";

  }
  else {
    if (selectedUnit != NULL) {
      unitName = selectedUnit->name; //change this later
      positionString = "Position: (";
      positionString.append(toString(selectedUnit->x));
      positionString.append(std::string(","));
      positionString.append(toString(selectedUnit->y));
      positionString.append(std::string(")"));

      HPString = "HP: ";
      HPString.append(toString(selectedUnit->HP));
      HPString.append(std::string(" / "));
      HPString.append(toString(selectedUnit->maxHP));
      powerString = "Power: ";
      powerString.append(toString(selectedUnit->power));
      rangeString = "Range: ";
      if (game.currentPhase < 2) {
	rangeString.append(toString(selectedUnit->moveRange));
      }
      else {
	rangeString.append(toString(selectedUnit->attackRange));
      }
      readyString = "Ready? : ";
      if (selectedUnit->ready) {
	readyString.append("YES");
      }
      else {readyString.append("NO");}
      
    }
    else {
      unitName = hoveredUnit->name; //change this later
      positionString = "Position: (";
      positionString.append(toString(hoveredUnit->x));
      positionString.append(std::string(","));
      positionString.append(toString(hoveredUnit->y));
      positionString.append(std::string(")"));

      HPString = "HP: ";
      HPString.append(toString(hoveredUnit->HP));
      HPString.append(std::string(" / "));
      HPString.append(toString(hoveredUnit->maxHP));
      powerString = "Power: ";
      powerString.append(toString(hoveredUnit->power));
      rangeString = "Range: ";
      if (game.currentPhase < 2) {
	rangeString.append(toString(hoveredUnit->moveRange));
      }
      else {
	rangeString.append(toString(hoveredUnit->attackRange));
      }
      readyString = "Ready? : ";
      if (hoveredUnit->ready) {
	readyString.append("YES");
      }
      else {readyString.append("NO");}
      
    }
  }
}
