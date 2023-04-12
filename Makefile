all: main.o
	g++ main.o -std=c++11 -o main

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

clean:
	rm *.o
	rm main
