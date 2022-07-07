#ifndef STACK_H
#define STACK_H
#include <stdexcept>
#include "Node.h"

template <typename T>
class Stack
{
    public:
	Stack();
    ~Stack();
    
	/** 
    * @pre stack is non-empty
    * @post copy the stack
    * @throw None
    **/
	Stack(const Stack<T>& orig);

	/** 
    * @pre stack is non-empty
    * @post make one stack the same as another one
    * @throw None
    **/
	void operator=(const Stack<T>& rhs);

	/** 
    * @pre stack is non-empty
    * @post entry is added to top of the stack
    * @throw None
    **/	
	void push(T entry);

	/** 
    * @pre stack is non-empty
    * @post Top element is removed from the stack
    * @throw None  
    **/
	void pop();

	/** 
    * @pre stack is non-empty
    * @post To return the Top element
    * @throw m_top  
    **/
	T peek() const;

	/** 
    * @pre 
    * @post To check whether the stack is empty or not
    * @throw true or false  
    **/
	bool isEmpty() const;
	


	private:
	Node<T>* m_top;	
};

#include "Stack.cpp"
#endif
