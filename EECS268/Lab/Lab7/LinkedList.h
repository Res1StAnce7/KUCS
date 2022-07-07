#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdexcept>
#include "Node.h"

template <typename T>
class LinkedList
{
    public:
    LinkedList();
    ~LinkedList();

    /**
    * @pre The index is valid
    * @post The entry is added to the list at the index, increasing length by 1
    * @param index, position to insert at (1 to length+1)
    * @param entry, value/object to add to the list
    * @throw std::runtime_error if the index is invalid
    */
    void insert(int index, T entry);

    /**
    * @pre The index is valid
    * @post The entry at given position is removed, reducing length by 1 
    * @param index, position to remove at (1 to length)
    * @throw std::runtime_error if the index is invalid
    */    
    void remove(int index);

    /**
    * @pre The index is valid
    * @post None 
    * @param index, position to get entry at (1 to length)
    * @throw std::runtime_error if the index is invalid
    * @return entry
    */
    T getEntry(int index) const;

    /**
    * @pre None
    * @post None 
    * @throw None
    * @return length
    */
    int length() const;

    /**
    * @pre None
    * @post List is empty
    * @throw None
    */
    void clear();

    /**
    * @pre The index is valid (must already exist)
    * @post Given entry overrides the entry at the given index 
    * @param index, position to override at (1 to length)
    * @param entry, value/object to place at given index
    * @throw std::runtime_error if the index is invalid
    */    
    void setEntry(int index, T entry);

    private:
    Node<T>* m_front;
    int m_length;
};

#include "LinkedList.cpp"
#endif

