#include "Tile.hpp"

Tile::Tile(int x, int y) {
  id = 0;
  this->x = x;
  this->y = y;
  
  sf::Sprite whiteTileSprite(whiteTile);
  sf::Sprite redTileSprite(redTile);
  sf::Sprite blueTileSprite(blueTile);
  
  sprites.push_back(whiteTileSprite);
  sprites.push_back(redTileSprite);
  sprites.push_back(blueTileSprite);
  
    
  for (int i=0;i<sprites.size();i++) {
    sprites.at(i).setOrigin(224/2, 224/2);
    sprites.at(i).setPosition(x,y);
  }
  
}

void Tile::step(sf::RenderWindow& window) {
  //check for capture
  if (containedSpritesp1() != containedSpritesp2()) {
    if (containedSpritesp1() == 0) { //goes to p2
      id = 2;
    }
    else if (containedSpritesp2() == 0) { //goes to p1
      id = 1;
    }
  }
  window.draw(sprites.at(id));
}

int Tile::containedSpritesp1() {
  int count=0;
  for (unitIterator=p1Units.begin();unitIterator!=p1Units.end();++unitIterator) {
    if (sprites.at(id).getGlobalBounds().contains((*unitIterator)->x, (*unitIterator)->y)) {
	count++;
    }
  }
  return count;
}

int Tile::containedSpritesp2() {
  int count=0;
  for (unitIterator=p2Units.begin();unitIterator!=p2Units.end();++unitIterator) {
    if (sprites.at(id).getGlobalBounds().contains((*unitIterator)->x, (*unitIterator)->y)) {
	count++;
    }
  }
  return count;
}
