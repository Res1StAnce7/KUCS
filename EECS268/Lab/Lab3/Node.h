#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
	private:
	T m_entry;
	Node<T>* m_next;
	
	public:
	Node(T entry);

	/** 
    * @pre 
    * @post get the entry
    * @throw m_entry  
    **/
	T getEntry() const;

	/** 
    * @pre 
    * @post set the entry
    * @throw   
    **/
	void setEntry(T entry);

	/** 
    * @pre 
    * @post get the node
    * @throw   
    **/
	Node<T>* getNext() const;

	/** 
    * @pre 
    * @post set the next node
    * @throw   
    **/
	void setNext(Node<T>* next);
};

#include "Node.cpp"
#endif