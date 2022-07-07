#ifndef BSTINTERFACE_H
#define BSTINTERFACE_H

template <typename ItemType, typename KeyType>
class BSTInterface
{
    public:
    virtual ~BSTInterface(){}
    virtual void add(ItemType entry) = 0; //throws std::runtime_error if duplicate added
    virtual ItemType search(KeyType key) const = 0; //throws std::runtime_error if not in tree
    virtual void clear() = 0; //Empties the tree
    virtual void remove(KeyType key) = 0; //throws std::runtime_error if not in tree
    virtual void visitPreOrder(void visit(ItemType)) const = 0; //Visits each node in pre order
    virtual void visitInOrder(void visit(ItemType)) const = 0; //Visits each node in in order
    virtual void visitPostOrder(void visit(ItemType)) const = 0; //Visits each node in post order
};

#include "BSTInterface.cpp"
#endif 
