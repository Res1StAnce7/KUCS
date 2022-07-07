lab03: main.o Executive.o Process.o
	g++ -std=c++11 -g -Wall main.o Executive.o Process.o -o lab03

main.o: main.cpp 
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp Process.h
	g++ -std=c++11 -g -Wall -c Executive.cpp

Process.o: Process.h Process.cpp Stack.h Stack.cpp Queue.h Queue.cpp Node.h Node.cpp
	g++ -std=c++11 -g -Wall -c Process.cpp

clean: 
	del *.o lab03


