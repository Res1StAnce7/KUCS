prog: main.o 
	g++ -std=c++11 -g -Wall main.o -o prog

main.o: main.cpp MinHeap.h
	g++ -std=c++11 -g -Wall -c main.cpp

clean: 
	del *.o prog
	del *.exe prog