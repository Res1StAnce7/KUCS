prog: main.o
	g++ -std=c++11 -g -Wall main.o -o prog
	
main.o: main.cpp Stack.h Stack.cpp Node.h Node.cpp 
	g++ -std=c++11 -g -Wall -c main.cpp

clean:
	del *.o prog