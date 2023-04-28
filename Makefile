all: main.o Qmain.o
	g++ main.o -std=c++11 -o main
	g++ Qmain.o -std=c++11 -o Qmain
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
Qmain.o: Qmain.cpp
	g++ -std=c++11 -c Qmain.cpp

clean:
	rm *.o
	rm main
	rm Qmain
