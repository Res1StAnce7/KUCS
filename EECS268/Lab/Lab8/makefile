prog: main.o Executive.o Pokemon.o 
	g++ -std=c++17 -g -Wall main.o Executive.o Pokemon.o -o prog
	
main.o: main.cpp 
	g++ -std=c++17 -g -Wall -c main.cpp

Executive.o: Executive.cpp Executive.h BST.h Pokemon.h
	g++ -std=c++17 -g -Wall -c Executive.cpp

Pokemon.o: Pokemon.cpp Pokemon.h
	g++ -std=c++17 -g -Wall -c Pokemon.cpp

clean:
	del *.o prog
	del *.exe prog