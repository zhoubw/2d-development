#include <SFML/Graphics.hpp>
#include <SFML/Graphics/View.hpp>
#include <iostream>

class Camera {
 

  //sf::View mainView(sf::floatRect(0,0,300,300));
  
public:
  sf::Texture texMap;
  sf::Sprite map;
  sf::FloatRect rectangle;
  sf::View mainView;
  Camera() {
    texMap.loadFromFile("maptest.jpg");
    map.setTexture(texMap);
    //new(&rectangle) sf::FloatRect(0,0,512,384);
    //new(&mainView) sf::View(rectangle);
    rectangle = sf::FloatRect(0,0,512,384);
    mainView = sf::View(rectangle);
  }
  
};
