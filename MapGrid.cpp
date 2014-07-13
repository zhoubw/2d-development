#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include "MapGrid.hpp"
#include <iostream>
#include <sstream>

int MapGrid::boxSize = 16;
//MapGrid::MapGrid() {
//  boxSize = 16;
//}

void MapGrid::partition(int width=1280, int height=720) {
  // map = new int[width/boxSize][height/boxSize];
  map = new int*[width/boxSize];
  for (int i=0; i<(width/boxSize); i++) {
    map[i] = new int[height/boxSize];
  }
}
