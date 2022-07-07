/**
 * @file Process.cpp
 * @author Siliang Zhang
 * @brief This file will model processes
 * @date 2021-03-10
 */
#include <iostream>
#include "Process.h"
#include "Stack.h"
using namespace std;

Process::Process()
{
    function = new Stack<string>();
    trycatch = new Stack<string>();
}

Process::~Process()
{
    if(function != nullptr)
    {
        while(!function->isEmpty())
        {
            function->pop();
        }
        delete function;
    }

    if(trycatch != nullptr)
    {
        while(!trycatch->isEmpty())
        {
            trycatch->pop();
        }
        delete trycatch;
    }
}

void Process::START(string processName) const
{
    function->push("main");  
    trycatch->push("try_catch");
    cout << ""<<processName<<" added to the queue" << endl;
}

void Process::CALL(string frontName, string functionName, string order) const
{
    function->push(functionName);  
    trycatch->push(order);
    cout << ""<<frontName<<" calls "<<functionName<<"" << endl;                                            
}

bool Process::RETURN(string frontName) const
{
    if(!function->isEmpty())
    {
        if(function->peek() == "main")
        {
            cout << ""<<frontName<<" "<<function->peek()<<" function returned and "<<frontName<<" ends" << endl;  
            function->pop();
            trycatch->pop();
            return(true);
        }

        else
        {
            cout << ""<<frontName<<" "<<function->peek()<<" function returned" << endl;
            function->pop();
            trycatch->pop();
            return(false);
        }
    }
}

bool Process::THROW(string frontName) const
{
    while(function->peek() == "main" || trycatch->peek() != "try_catch")
    {
        if(function->peek() == "main")
        {
            cout << ""<<frontName<<" terminated due to unhandled exception" << endl;
            return(true);
        }

        else
        {
            function->pop();
            trycatch->pop();
        }   
    }

    if(trycatch->peek() == "try_catch" && function->peek() != "main")
    {
        cout << ""<<frontName<<" exception caught by "<<function->peek()<<" function" << endl;
        return(false);
    }
}