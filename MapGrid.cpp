#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include "MapGrid.hpp"
#include "main.hpp"
#include <iostream>
#include <sstream>

const int boxSize = 16;
const int w = 1280; //window
const int h = 720; //window

//MAP 1920x1080
//blocks 120x67

const int constW = w/boxSize;
const int constH = h/boxSize;

sf::Sprite sprite;

//std::vector<sf::Sprite> bSTemplate(h/boxSize,sprite);
//std::vector<std::vector<sf::Sprite> > blockSprites(w/boxSize,bSTemplate);

sf::Sprite blockSprites[120][67];
sf::Texture txtre;
const sf::Texture* blockTexture = &txtre;
sf::Sprite blockSprite;

void fill200() {
  txtre.loadFromFile("TestBlock.png");
  blockSprite.setTexture(txtre);
  
 
  for (int i=0; i<60; i++) {
    blockSprites[i][13] = blockSprite;
  }
  for (int i=60; i<120; i++) {
    blockSprites[i][20] = blockSprite;
  }
  
  for (int i=0; i<120; i++) {
    for (int j=0; j<67; j++) {
      if (i!= 10) {
	blockSprites[i][j].setPosition(i*16, j*16);
	window.draw(blockSprites[i][j]);
      }
    }
  }
  
 
}

//prints blockSprites
/*
void printBlockSprites() {
  
  for (int i=0; i<80; i++) {
    for (int j=0; j<45; j++) {
      std::cout << blockSprites[i][j].getTexture();
    }
  }
  std::cout << std::endl;
  
}
*/

