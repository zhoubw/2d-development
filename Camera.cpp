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
  int dim_x;
  int dim_y;
  Camera() {
    texMap.loadFromFile("maptest.jpg");
    map.setTexture(texMap);
    dim_x = 1280;
    dim_y = 720;
    //new(&rectangle) sf::FloatRect(0,0,512,384);
    //new(&mainView) sf::View(rectangle);
    //rectangle = sf::FloatRect(0,0,dim_x/2,dim_y/2);
    rectangle = sf::FloatRect(0,0,dim_x,dim_y);
    mainView = sf::View(rectangle);
  }
  
};
