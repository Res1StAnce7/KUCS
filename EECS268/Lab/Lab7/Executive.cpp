/**
 * @file Executive.cpp
 * @author Siliang Zhang
 * @brief This file will record the time of execution of 6 operations
 * @date 2021-04-11
 */
#include "Executive.h"
#include <iostream>
#include <fstream>
#include <time.h>
#include "Stack.h"
#include "Queue.h"
#include "LinkedList.h"
using namespace std;

Executive::Executive()
{
    start = 0.0;
    end = 0.0;
    num = 1000;
}

void Executive::run()
{
    Stack_pop();
    Stack_destructor();
    Queue_enqueue();
    LinkedList_FirstIndex();
    LinkedList_LastIndex();
    Print_Elements();
}

void Executive::Stack_pop()
{
    ofstream outFile1("Stack's_pop.txt");
    Stack<char> stack;
    
    cout << "Stack's pop" << endl;

    do
    {
        for(int i=0; i<num; i++)
        {
            stack.push('a');
        }

        start = clock();
        for(int i=0 ;i<num; i++)
        {
            stack.pop();
        }
        end = clock();

        outFile1 << "Time of popping "<<num<<" elements: "<<double(end-start)/CLOCKS_PER_SEC<<"s" << endl;
        cout << "Time of popping "<<num<<" elements: "<<double(end-start)/CLOCKS_PER_SEC<<"s" << endl;
        
        num = num + 1000;
    } while (num != 101000);
    cout << endl;

    num = 1000;
}

void Executive::Stack_destructor()
{
    ofstream outFile2("Stack's_destructor.txt"); 
    Stack<char> destruct;
    cout << "Stack's destructor" << endl;
    
    do
    {    
        for(int i=0; i<num; i++)
        {
            destruct.push('a');
        }

        start = clock();
        for(int i=9; i<num; i++)
        {
            destruct.~Stack();
        }
        end = clock();

        outFile2 << "Time of destructing while "<<num<<" elements in the Stack object: "<<double(end-start)/CLOCKS_PER_SEC<<"s" << endl;
        cout << "Time of destructing while "<<num<<" elements in the Stack object: "<<double(end-start)/CLOCKS_PER_SEC<<"s" << endl;
        
        num = num + 1000;
    } while (num != 101000);
    cout << endl;

    num = 1000;
}

void Executive::Queue_enqueue()
{
    ofstream outFile3("Queue's_enqueue.txt");
    Queue<char> queue;
    cout << "Queue's enqueue" << endl;
    
    do
    {
        start = clock();
        for(int i=0; i<num; i++)
        {
            queue.enqueue('a');
        }
        end = clock();

        outFile3 << "Time of enqueuing "<<num<<" elements: "<<double(end-start)/CLOCKS_PER_SEC<<"s" << endl;
        cout << "Time of enqueuing "<<num<<" elements: "<<double(end-start)/CLOCKS_PER_SEC<<"s" << endl;
        
        for(int i=0; i<num; i++)
        {
            queue.dequeue();
        }

        num = num + 1000;
    } while (num != 101000);
    cout << endl;

    num = 1000;
}


void Executive::LinkedList_FirstIndex()
{
    ofstream outFile4("LinkedList_getEntry_FirstIndex.txt");
    LinkedList<char> list;
    cout << "Linked List getEntry at specifically index 1" << endl;
    
    do
    {
        for(int i=1; i<num+1; i++)
        {
            try
            {
                list.insert(i,'a');
            }
            catch(runtime_error& rte)
            {
                cerr << rte.what() << endl;
            }
        }

        start = clock();
        list.getEntry(1);
        end = clock();

        outFile4 << "Time of getEntry at index 1 while "<<num<<" elements in the LinkedList: "<<double(end-start)/CLOCKS_PER_SEC<<"s" << endl;
        cout << "Time of getEntry at index 1 while "<<num<<" elements in the LinkedList: "<<double(end-start)/CLOCKS_PER_SEC<<"s" << endl;
        
        num = num + 1000;
    } while (num != 101000);
    cout << endl;

    num = 1000;
}

void Executive::LinkedList_LastIndex()
{
    ofstream outFile5("LinkedList_getEntry_LastIndex.txt");
    LinkedList<char> list;
    cout << "Linked List getEntry at specifically the last index" << endl;
    
    do
    {
        for(int i=1; i<num+1; i++)
        {
            try
            {
                list.insert(i,'a');
            }
            catch(runtime_error& rte)
            {
                cerr << rte.what() << endl;
            }
        }

        start = clock();
        list.getEntry(num);
        end = clock();

        outFile5 << "Time of getEntry at the last index while "<<num<<" elements in the LinkedList: "<<double(end-start)/CLOCKS_PER_SEC<<"s" << endl;
        cout << "Time of getEntry at last index while "<<num<<" elements in the LinkedList: "<<double(end-start)/CLOCKS_PER_SEC<<"s" << endl;
        
        num = num + 1000;
    } while (num != 101000);
    cout << endl;

    num = 1000;
}

void Executive::Print_Elements()
{
    ofstream outFile6("Print.txt");
    LinkedList<char> list;
    cout << "Printing all elements in a LinkedList using getEntry" << endl;

    do
    {
        for(int i=1; i<=num; i++)
        {
            try
            {
                list.insert(i,'a');
            }
            catch(runtime_error& rte)
            {
                cerr << rte.what() << endl;
            }
        }

        start = clock();
        for(int i=1; i<=num; i++)
        {
            try
            {
                cout << "Element #"<<i<<": "<<list.getEntry(i)<<"" << endl;
            }
            catch(runtime_error& rte)
            {
                cerr << rte.what() << endl;
            }
        }
        end = clock();

        outFile6 << "Time of printing all elements using getEntry while "<<num<<" elements in the LinkedList: "<<double(end-start)/CLOCKS_PER_SEC<<"s" << endl;
        cout << "Time of printing all elements using getEntry while "<<num<<" elements in the LinkedList: "<<double(end-start)/CLOCKS_PER_SEC<<"s" << endl;

        num = num + 1000;
    } while (num != 101000);
    cout << endl;
    
    num = 1000;
}
