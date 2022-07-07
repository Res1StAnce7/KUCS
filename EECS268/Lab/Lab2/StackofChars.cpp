/**
 * @file StackofChars.cpp
 * @author Siliang Zhang
 * @brief This file will verify whether the sequence of left and right curly braces is balanced or not.
 * @date 2021-03-03
 */
#include "StackofChars.h"
#include "Node.h"

StackofChars::StackofChars()
{
	m_top = nullptr;
}

bool StackofChars::isEmpty() const
{
	return(m_top == nullptr);
}

StackofChars::~StackofChars()
{
	while(m_top != nullptr)
    { 
       Node* temp = m_top;
       m_top = m_top->getNext();
       delete temp;
    }

	delete m_top;
}

void StackofChars::push(char entry) 
{
    if(isEmpty())
	{
        m_top = new Node(entry);
    }

    else{
	    Node* temp = m_top;
	    m_top= new Node(entry);
	    m_top->setNext(temp);
	}   
}

void StackofChars::pop()
{
	if(m_top != nullptr)
    {
        Node *temp = m_top;
        m_top = m_top->getNext();
        delete(temp);
    }
}

char StackofChars::peek() const
{
    return(m_top->getEntry());	
}

void StackofChars::clear()
{
    while(m_top != nullptr)
    {
        Node* temp = m_top;
        m_top = m_top->getNext();
        delete temp;
    }
}