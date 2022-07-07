#ifndef STACK_H
#define STACK_H
#include "Node.h"

template <typename T>
class Stack
{
    public:
    Stack();
    ~Stack();
    void push(T entry); //add to the top
    void pop(); // remove top entry
    T peek() const; //look at top entry
    bool isEmpty() const;

    private:
    Node<T>* m_top;
};

#include "Stack.cpp"
#endif