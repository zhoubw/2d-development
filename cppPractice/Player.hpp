//Header file for Player

class Player {
public: 
  int x, y;
  int speed, dY;
  int g;
  int width;
  int height;
  int fallFrame;

  sf::RectangleShape shape;

  void move(int x,int y);
  void fall();
  Player(int,int);
};
