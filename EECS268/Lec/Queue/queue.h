#ifndef QUEUE_H
#define QUEUE_H
#include <stdexcept>
#include "Node.h"

template <typename T>
class Queue
{
    public:
    Queue();
    ~Queue();
    Queue(const Queue<T>& orig);
    void operator=(const Queue<T>& rhs);
    void enqueue(T entry); //add to the back
    void dequeue(); // remove front entry
    T peekFront() const; //look at top entry
    bool isEmpty() const;

    private:
    Node<T>* m_front
    Node<T>* m_back;
};

#include "Queue.cpp"
#endif