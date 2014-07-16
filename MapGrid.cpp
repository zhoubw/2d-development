#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include "MapGrid.hpp"
#include <iostream>
#include <sstream>

const int boxSize = 16;
const int w = 1280;
const int h = 720;

const int constW = w/boxSize;
const int constH = h/boxSize;

sf::Sprite sprite;

//std::vector<sf::Sprite> bSTemplate(h/boxSize,sprite);
//std::vector<std::vector<sf::Sprite> > blockSprites(w/boxSize,bSTemplate);

sf::Sprite blockSprites[80][45];
sf::Texture blockTexture;
sf::Sprite blockSprite;

void fill200() {
  blockTexture.loadFromFile("TestBlock.png");
  blockSprite.setTexture(blockTexture);
  
 
  for (int i=0; i<80; i++) {
  blockSprites[i][13] = blockSprite;
  }
 
}

//prints blockSprites
void printBlockSprites() {
  for (int i=0; i<80; i++) {
    for (int j=0; j<45; j++) {
      std::cout << &blockSprites[i][j];
    }
  }
  std::cout << std::endl;
}
