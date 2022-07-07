lab01: main.o Executive.o Game.o
	g++ -std=c++11 -g -Wall main.o Executive.o Game.o -o lab01

main.o: main.cpp Executive.h Game.h
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.cpp Executive.h Game.h
	g++ -std=c++11 -g -Wall -c Executive.cpp

Game.o: Game.h Game.cpp  
	g++ -std=c++11 -g -Wall -c Game.cpp

clean: 
	del *.o lab01
	del *.exe lab01