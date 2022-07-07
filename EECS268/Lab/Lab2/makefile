lab02: main.o StackTester.o StackofChars.o Node.o
	g++ -std=c++11 -g -Wall main.o StackofChars.o StackTester.o Node.o -o lab02

main.o: main.cpp 
	g++ -std=c++11 -g -Wall -c main.cpp

StackTester.o: StackTester.h StackTester.cpp StackofChars.h
	g++ -std=c++11 -g -Wall -c StackTester.cpp

StackofChars.o: StackofChars.h StackofChars.cpp Node.h
	g++ -std=c++11 -g -Wall -c StackofChars.cpp

Node.o: Node.cpp Node.h
	g++ -std=c++11 -g -Wall -c Node.cpp

clean: 
	del *.o lab02
	del *.exe lab02
	