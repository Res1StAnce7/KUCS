/**
 * @file LinkedList.cpp
 * @author Siliang Zhang
 * @brief This file will implement a templated linked list
 * @date 2021-03-22
 */
#include "Node.h"
#include <iostream>
template <typename T>
LinkedList<T>::LinkedList()
{
    m_front = nullptr;
    m_length = 0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    clear();
}

template <typename T>
void LinkedList<T>::insert(int index, T entry)
{
    if (index > m_length + 1 || index < 1)
    {
        throw(runtime_error("Invalid index"));
    }

    else if (index == 1)
    {
        Node<T> *temp = m_front;
        m_front = new Node<T>(entry);
        m_front->setNext(temp);
        m_length++;
    }

    else if (index == m_length + 1)
    {
        Node<T> *temp = new Node<T>(entry);
        Node<T> *jumper = m_front;
        for (int i = 2; i <= index - 1; i++)
        {
            jumper = jumper->getNext();
        }
        jumper->setNext(temp);
        m_length++;
    }

    else
    {
        Node<T> *temp = new Node<T>(entry);
        Node<T> *jumper = m_front;

        for (int i = 2; i <= index - 1; i++)
        {
            jumper = jumper->getNext();
        }

        Node<T> *entryAfterIndex = jumper->getNext();
        jumper->setNext(temp);
        temp->setNext(entryAfterIndex);
        m_length++;
    }
}

template <typename T>
void LinkedList<T>::remove(int index)
{
    if (index > m_length || index < 1)
    {
        throw(runtime_error("Invlid index"));
    }

    else if (index == 1)
    {
        Node<T> *temp = m_front;
        m_front = m_front->getNext();
        delete temp;
        m_length--;
    }

    else
    {
        Node<T> *jumper1 = m_front;
        Node<T> *jumper2 = m_front;

        for (int i = 0; i < index - 1; i++)
        {
            jumper1 = jumper1->getNext();
        }

        Node<T> *temp = jumper1;
        jumper1 = jumper1->getNext();
        delete temp;
        m_length--;

        for (int i = 0; i < index - 2; i++)
        {
            jumper2 = jumper2->getNext();
        }
        jumper2->setNext(jumper1);
    }
}

template <typename T>
T LinkedList<T>::getEntry(int index) const
{
    if (index > m_length || index < 1)
    {
        throw runtime_error("Invalid index");
    }
    
    else
    {
        Node<T> *jumper = m_front;

        for (int i = 1; i <= m_length; i++)
        {
            if (i == index)
            {
                return(jumper->getEntry());
            }
            jumper = jumper->getNext();
        }
    }
}

template <typename T>
int LinkedList<T>::length() const
{
    return(m_length);
}

template <typename T>
void LinkedList<T>::clear()
{
    int index = 1;
    while (m_front != nullptr)
    {
        remove(index);
    }
}

template <typename T>
void LinkedList<T>::setEntry(int index, T entry)
{
    if (index > m_length || index < 1)
    {
        throw runtime_error("Invalid index");
    }

    Node<T> *jumper = m_front;

    for (int i = 1; i <= m_length; i++)
    {
        if (i == index)
        {
            jumper->setEntry(entry);
            break;
        }
        jumper = jumper->getNext();
    }
}
