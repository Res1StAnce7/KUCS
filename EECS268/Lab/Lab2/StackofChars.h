/**
 * @file StackofChars.h
 * @author Siliang Zhang
 * @brief It is the header file of StackofChars.cpp
 * @date 2021-03-03
 */
#ifndef STACKOFCHARS_H
#define STACKOFCHARS_H
#include "Node.h"

class StackofChars
{
	public:
	
	StackofChars();

    ~StackofChars();
	
    /** 
    * @pre None
    * @post entry is added to top of the stack
    * @param entry, the element to be added to the stack
    * @throw None
    **/
	void push(char entry);
	
    /** 
    * @pre Stack is non-empty
    * @post Top element is removed from the stack
    * @param None
    * @throw None  
    **/
	void pop();
	
    /** 
    * @pre Stack is non-empty
    * @post To return the Top element
    * @param None
    * @throw m_top  
    **/
	char peek() const;
    
    /** 
    * @pre 
    * @post To check whether the stack is empty or not
    * @param None
    * @throw true or false  
    **/
	bool isEmpty() const; 

    /** 
    * @pre Stack is non-empty
    * @post Stack is empty
    * @param None
    * @throw none  
    **/
    void clear();

    private:
	Node* m_top;
};

#endif