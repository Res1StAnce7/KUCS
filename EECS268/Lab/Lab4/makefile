prog: main.o Executive.o ShapeContainer.o Shape.o Circle.o Triangle.o Rectangle.o
	g++ -std=c++11 -g -Wall main.o Executive.o ShapeContainer.o Shape.o Circle.o Triangle.o Rectangle.o -o prog

main.o: main.cpp  
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.cpp Executive.h ShapeContainer.h Shape.h Circle.h Triangle.h Rectangle.h
	g++ -std=c++11 -g -Wall -c Executive.cpp

ShapeContainer.o: ShapeContainer.cpp ShapeContainer.h Shape.h
	g++ -std=c++11 -g -Wall -c ShapeContainer.cpp

Shape.o: Shape.cpp Shape.h  
	g++ -std=c++11 -g -Wall -c Shape.cpp

Circle.o: Circle.cpp Circle.h Shape.h
	g++ -std=c++11 -g -Wall -c Circle.cpp

Triangle.o: Triangle.cpp Triangle.h Shape.h
	g++ -std=c++11 -g -Wall -c Triangle.cpp

Rectangle.o: Rectangle.cpp Rectangle.h Shape.h
	g++ -std=c++11 -g -Wall -c Rectangle.cpp

clean: 
	del *.o prog
	del *.exe prog
	
