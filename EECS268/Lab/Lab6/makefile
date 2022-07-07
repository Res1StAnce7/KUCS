prog: main.o Traverse.o FileReader.o
	g++ -std=c++11 -g -Wall main.o Traverse.o FileReader.o -o prog
	
main.o: main.cpp Traverse.h
	g++ -std=c++11 -g -Wall -c main.cpp

Traverse.o: Traverse.cpp Traverse.h FileReader.h
	g++ -std=c++11 -g -Wall -c Traverse.cpp

FileReader.o: FileReader.cpp FileReader.h
	g++ -std=c++11 -g -Wall -c FileReader.cpp
	
clean:
	del *.o prog
	del *.exe prog
