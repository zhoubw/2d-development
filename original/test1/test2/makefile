CC=g++ -c -I/usr/local/lib

all: sfml-app
	export LD_LIBRARY_PATH=/usr/local/lib

sfml-app: main.o
	g++ main.o -o sfml-app -L/usr/local/lib -lsfml-system -lsfml-graphics -lsfml-window -lBox2D

main.o: main.cpp
	$(CC) main.cpp

clean:
	rm -f *.o sfml-app