#ifndef PROCESS_H
#define PROCESS_H
#include <string>
#include "Stack.h"
using namespace std;

class Process
{
    public:
    Process();
    ~Process();

    /** 
    * @pre 
    * @post make the START call and store "main" into the stack and try_catch block into two stacks
    * @throw 
    **/
    void START(string processName) const;

    /** 
    * @pre 
    * @post make the CALL call and store the function and try_catch block into two stacks
    * @throw 
    **/
    void CALL(string frontName, string functionName, string order) const;

    /** 
    * @pre 
    * @post make the RETURN call, return the function and removed the process if main is returned
    * @throw 
    **/
    bool RETURN(string frontName) const;

    /** 
    * @pre 
    * @post make the THROW call, catch exceptions and removed the process if main is returned
    * @throw 
    **/
    bool THROW(string frontName) const;
    
    private:
    Stack<string>* function;
    Stack<string>* trycatch;

};

#endif
