/**
 * @file Node.cpp
 * @author Siliang Zhang
 * @brief This file will implement the function of Nodes.
 * @date 2021-03-03
 */
#include "Node.h"
Node::Node(char entry)
{
	m_entry = entry;
	m_next = nullptr;
}

char Node::getEntry() const
{
	return(m_entry);
}

void Node::setEntry(char entry)
{
	m_entry = entry;
}

Node* Node::getNext() const
{
	return(m_next);
}

void Node::setNext(Node* next)
{
	m_next = next;
}