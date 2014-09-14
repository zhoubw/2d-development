//Header file for Player

class Player {
public: 
  
  int x1;
  int x2;
  int x3;
  int y1;
  int y2;
  int y3;
  
  int x, y;
  int speed, jumpSpeed, dX, dY;
  int g;
  int width;
  int height;
  int fallFrame;
  bool jumping;

  int hp;
  int maxHp;
  int hpBar;
  
  sf::Texture texture;
  //temp
  sf::RectangleShape shape;
  sf::Sprite sprite;

  void move(int x,int y);
  void fall();
  void jump();
  bool grounded();
  bool capped();
  bool blockedLeft();
  bool blockedRight();
  void step();
  Player(int,int);
};
