CC=g++ -c -I/usr/local/lib

all: sfml-app
	export LD_LIBRARY_PATH=/usr/local/lib

sfml-app: main.o Unit.o Gui.o Game.o Tile.o
	g++ main.o Unit.o Gui.o Game.o Tile.o -o sfml-app -L/usr/local/lib -lsfml-system -lsfml-graphics -lsfml-window

main.o: main.cpp
	$(CC) main.cpp

Unit.o: Unit.cpp
	$(CC) Unit.cpp

Gui.o: Gui.cpp
	$(CC) Gui.cpp

Game.o: Game.cpp
	$(CC) Game.cpp

Tile.o: Tile.cpp
	$(CC) Tile.cpp

clean:
	rm -f *.o sfml-app *~
