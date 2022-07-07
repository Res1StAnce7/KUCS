#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include <time.h>
using namespace std;

class Executive
{
    public:
    Executive();
    void run();
    void Stack_pop();
    void Stack_destructor();
    void Queue_enqueue();
    void LinkedList_FirstIndex();
    void LinkedList_LastIndex();
    void Print_Elements();

    private:
    clock_t start;
    clock_t end;
    int num;
};

#endif
