prog: main.o Executive.o
	g++ -std=c++17 -g -Wall main.o Executive.o -o prog
	
main.o: main.cpp Executive.h
	g++ -std=c++17 -g -Wall -c main.cpp

Executive.o: Executive.cpp Executive.h Stack.h Queue.h LinkedList.h
	g++ -std=c++17 -g -Wall -c Executive.cpp

clean:
	rm *.o prog
