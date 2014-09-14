CC=g++ -c -I/usr/local/lib
all: sfml-app
	export LD_LIBRARY_PATH=/usr/local/lib

sfml-app: main.o Player.o Projectile.o Mirror.o Laser.o
	g++ main.o Player.o Projectile.o Mirror.o Laser.o -o sfml-app -L/usr/local/lib -lsfml-system -lsfml-graphics -lsfml-window

main.o: main.cpp
	$(CC) main.cpp

Player.o: Player.cpp
	$(CC) Player.cpp

Projectile.o: Projectile.cpp
	$(CC) Projectile.cpp

Mirror.o: Mirror.cpp
	$(CC) Mirror.cpp

Laser.o: Laser.cpp
	$(CC) Laser.cpp

clean:
	rm -rf *.o sfml-app