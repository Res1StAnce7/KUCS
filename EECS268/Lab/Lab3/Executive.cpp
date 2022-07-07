/**
 * @file Executive.cpp
 * @author Siliang Zhang
 * @brief This file will run the mock CPU scheduler
 * @date 2021-03-10
 */
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "Executive.h"
#include "Process.h"
#include "Queue.h"
using namespace std;

Executive::Executive(string lineCommand)
{
    Queue<Process*> Queue1;
    Queue<string> frontProcess;
    Pro = nullptr;
    m_lineCommand = lineCommand;
    m_count = 0;
}

void Executive::run()
{
   fstream inFile1;
   inFile1.open(m_lineCommand);
   string check;
   int count1 = 0;
   
    if(inFile1.is_open())
    {
        while(check.compare("CALL") != 0)
        {
            inFile1 >> check;
            if(check.compare("START") == 0)
            {
                count1++;
                m_count = count1;
            }   
        }  
    }

    else
    {
       cout << "The file cannot be opened!" << endl;
       abort();
    }

    Pro = new Process*[count1];
    for(int i=0; i<count1; i++){
        Pro[i] = new Process();
    }
    
    inFile1.close();

    fstream inFile2;
    inFile2.open(m_lineCommand);

    if(inFile2.is_open())
    {   
        Queue<string> Queue2;
        string command;
        string processName;
        string functionName;
        string order;
        bool mainReturn = true;
        int count2 = 0;
        inFile2 >> command;

        while(command.compare("END") != 0)
        {
            if(command.compare("START") == 0)
            {
                inFile2 >> processName;
                Queue1.enqueue(Pro[count2]);
                frontProcess.enqueue(processName);
                Pro[count2]->START(processName);
                count2++;
            }

            else if(command.compare("CALL") == 0)
            {
                inFile2 >> functionName;
                inFile2 >> order;
                Queue1.peekFront()->CALL(frontProcess.peekFront(), functionName, order);
                Queue1.enqueue(Queue1.peekFront());
                Queue1.dequeue();
                frontProcess.enqueue(frontProcess.peekFront());
                frontProcess.dequeue();
            }

            else if(command.compare("RETURN") == 0)
            {
                mainReturn = Queue1.peekFront()->RETURN(frontProcess.peekFront());
                if(mainReturn)
                {
                    Queue1.dequeue();
                    frontProcess.dequeue();
                }

                else
                {
                    Queue1.enqueue(Queue1.peekFront());
                    Queue1.dequeue();
                    frontProcess.enqueue(frontProcess.peekFront());
                    frontProcess.dequeue();
                }
            }

            else if(command.compare("THROW") == 0)
            {
                mainReturn = Queue1.peekFront()->THROW(frontProcess.peekFront());
                if(mainReturn)
                {
                    Queue1.dequeue();
                    frontProcess.dequeue();
                }

                else
                {
                    Queue1.enqueue(Queue1.peekFront());
                    Queue1.dequeue();
                    frontProcess.enqueue(frontProcess.peekFront());
                    frontProcess.dequeue();
                }
            }

        inFile2 >> command;
        }

        if(Pro != nullptr)
        {
            for(int i=0; i<m_count; i++)
            {
                delete Pro[i];
            }
            delete[] Pro;
        }

        while(!Queue1.isEmpty())
        {
            Queue1.dequeue();
        }

        while(!frontProcess.isEmpty())
        {
            frontProcess.dequeue();
        }
    }

    else
    {
       cout << "The file cannot be opened!" << endl;
       exit(0);
    }
}