//Header file for Player

class Player {
public: 
  int x, y;
  int speed, jumpSpeed, dX, dY;
  int g;
  int width;
  int height;
  int fallFrame;
  bool jumping;
  
  sf::Texture texture;
  //temp
  sf::RectangleShape shape;
  sf::Sprite sprite;

  void move(int x,int y);
  void fall();
  void jump();
  bool grounded();
  void step();
  Player(int,int);
};
