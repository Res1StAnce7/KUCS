#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "Process.h"
#include "Queue.h"
#include <string>
using namespace std;

class Executive
{
    public:
    Executive(string lineCommand);

    /** 
    * @pre 
    * @post run the CPU scheduler
    * @throw 
    **/
    void run();

    private:
    Queue<Process*> Queue1;
    Queue<string> frontProcess;
    string m_lineCommand;
    Process** Pro;
    int m_count;
};


#endif
