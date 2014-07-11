CC=g++ -c -I/usr/local/lib
all: sfml-app

sfml-app: main.o Player.o Camera.o
	g++ main.o Player.o Camera.o -o sfml-app -L/usr/local/lib -lsfml-system -lsfml-graphics -lsfml-window

main.o: main.cpp
	$(CC) main.cpp

Player.o: Player.cpp
	$(CC) Player.cpp

Camera.o: Camera.cpp
	$(CC) Camera.cpp

clean:
	rm -rf *.o sfml-app