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
	/** 
    * @pre queue is non-empty
    * @post copy the stack
    * @throw None
    **/
	Queue(const Queue<T>& orig);	

	/** 
    * @pre queue is non-empty
    * @post make one queue the same as another one
    * @throw None
    **/
	void operator=(const Queue<T>& rhs);	

	/** 
    * @pre queue is non-empty
    * @post entry is added to back of the queue
    * @throw None
    **/
	void enqueue(T entry);

	/** 
    * @pre queue is non-empty
    * @post entry is removed from front of the queue
    * @throw None
    **/
	void dequeue();

	/** 
    * @pre queue is non-empty
    * @post get the entry at front of the queue
    * @throw entry
    **/
	T peekFront() const;

	/** 
    * @pre
    * @post check if queue is empty
    * @throw true or false
    **/
	bool isEmpty() const;

	private:
	Node<T>* m_front;
	Node<T>* m_back;		
};

#include "Queue.cpp"
#endif