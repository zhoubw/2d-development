CC=g++ -c -I/usr/local/lib

all: sfml-app
	export LD_LIBRARY_PATH=/usr/local/lib

sfml-app: main.o Unit.o Player.o Projectile.o
	g++ main.o Unit.o Player.o Projectile.o -o sfml-app -L/usr/local/lib -lsfml-system -lsfml-graphics -lsfml-window -lBox2D

main.o: main.cpp
	$(CC) main.cpp

Unit.o: Unit.cpp
	$(CC) Unit.cpp

Player.o: Player.cpp
	$(CC) Player.cpp

Projectile.o: Projectile.cpp
	$(CC) Projectile.cpp

clean:
	rm -f *.o sfml-app