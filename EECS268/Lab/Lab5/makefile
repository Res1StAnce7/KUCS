prog: main.o Executive.o BrowserHistory.o BrowserHistoryInterface.o
	g++ -std=c++11 -g -Wall main.o Executive.o BrowserHistoryInterface.o BrowserHistory.o -o prog

main.o: main.cpp 
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp BrowserHistory.h BrowserHistoryInterface.h ListInterface.h
	g++ -std=c++11 -g -Wall -c Executive.cpp

BrowserHistoryInterface.o: BrowserHistoryInterface.h BrowserHistoryInterface.cpp ListInterface.h
	g++ -std=c++11 -g -Wall -c BrowserHistoryInterface.cpp

BrowserHistory.o: BrowserHistory.h BrowserHistory.cpp BrowserHistoryInterface.h
	g++ -std=c++11 -g -Wall -c BrowserHistory.cpp

clean: 
	rm *.o prog

