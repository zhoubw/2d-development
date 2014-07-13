CC=g++ -c -I/usr/local/lib
all: sfml-app

sfml-app: main.o Player.o Camera.o MapGrid.o
	g++ main.o Player.o Camera.o MapGrid.o -o sfml-app -L/usr/local/lib -lsfml-system -lsfml-graphics -lsfml-window

main.o: main.cpp
	$(CC) main.cpp

Player.o: Player.cpp
	$(CC) Player.cpp

Camera.o: Camera.cpp
	$(CC) Camera.cpp

MapGrid.o: MapGrid.cpp
	$(CC) MapGrid.cpp

clean:
	rm -rf *.o sfml-app