//Header file for Player

class Player {
public: 
  int x, y;
  int speed, dY;
  int g;
  int width;
  int height;
  int fallFrame;
  bool jumping;

  sf::RectangleShape shape;

  void move(int x,int y);
  void fall();
  void jump();
  Player(int,int);
};
