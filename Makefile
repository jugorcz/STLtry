
all: main clean
	./main

main: main.o
	g++ -o main main.o -Wall -std=c++11

main.o: main.cpp
	g++ -c main.cpp -Wall -std=c++11

clean:
	rm -f *.o