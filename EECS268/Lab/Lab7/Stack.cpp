/**
 * @file Stack.cpp
 * @author Siliang Zhang
 * @brief This file will create templated Stack
 * @date 2021-04-11
 */
#include <stdexcept>

template <typename T>
Stack<T>::Stack()
{
	m_top = nullptr;
}

template <typename T>
Stack<T>::~Stack()
{
    while(!isEmpty())
    {
        pop();
    }
}

template <typename T>
void Stack<T>::push(T entry) 
{
    if(isEmpty())
	{
        m_top = new Node<T>(entry);
    }
    else
    {
	    Node<T>* temp = m_top;
	    m_top= new Node<T>(entry);
	    m_top->setNext(temp);
	}   
}

template <typename T>
Stack<T>::Stack(const Stack<T>& orig)
{
    Node<T>* jumper_s = orig.m_top;

    m_top = nullptr; 

    while(jumper_s != nullptr)
    {
        push(jumper_s->getEntry());
        jumper_s = jumper_s->getNext();
    }
}

template <typename T>
void Stack<T>::operator=(const Stack<T>& rhs)
{
    while(!isEmpty())
    {
        pop();
    }

    Node<T>* jumper_s = rhs.m_top;
    
    while(jumper_s != nullptr)
    {
        push(jumper_s->getEntry());
        jumper_s = jumper_s->getNext();
    }
}

template <typename T>
void Stack<T>::pop()
{
    if(m_top != nullptr)
    {
        Node<T>* temp = m_top;
        m_top = m_top->getNext();
        delete(temp);
    }
}

template <typename T>
T Stack<T>::peek() const
{
    if(!isEmpty())
	{
		return(m_top->getEntry());	
	}
}

template <typename T>
bool Stack<T>::isEmpty() const
{
	return(m_top == nullptr);
}
