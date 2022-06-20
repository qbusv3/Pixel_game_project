all: compile link

compile:
	g++ -c main.cpp -I/opt/homebrew/Cellar/sfml/2.5.1_1/include

link:
	g++ main.o -o main -L/opt/homebrew/Cellar/sfml/2.5.1_1/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio

clean:
	rm -f main *.o