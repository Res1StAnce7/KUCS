/**
 * @file Node.h
 * @author Siliang Zhang
 * @brief It is the header file of Node.cpp
 * @date 2021-03-03
 */
#ifndef NODE_H
#define NODE_H

class Node
{
    public:
    Node(char entry);
	char getEntry() const;
	void setEntry(char entry);
	Node* getNext() const;
	void setNext(Node* next);
    
    private:
    char m_entry;
    Node* m_next;
};

#endif