#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
    public:
    Node(T entry);
	T getEntry() const;
	void setEntry(T entry);
	Node<T>* getNext() const;
	void setNext(Node<T>* next);
    
    private:
    T m_entry;
    Node<T>* m_next;
};

#include "Node.cpp"
#endif