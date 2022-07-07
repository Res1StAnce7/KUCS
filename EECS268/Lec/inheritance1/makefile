prog: main.o Animal.o Dog.o 
	g++ -std=c++11 -g -Wall main.o Animal.o Dog.o -o prog

main.o: main.cpp  
	g++ -std=c++11 -g -Wall -c main.cpp

Animal.o: Animal.cpp Animal.h  
	g++ -std=c++11 -g -Wall -c Animal.cpp

Dog.o: Dog.h Dog.cpp Animal.h
	g++ -std=c++11 -g -Wall -c Dog.cpp

clean: 
	del *.o prog
	del *.exe prog