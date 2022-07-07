#ifndef BNODE_H
#define BNODE_H

template <typename ItemType>
class BNode
{
    public:
    BNode(ItemType entry);
    ItemType getLST();
    ItemType getRST();
    void setLST(ItemType entry);
    void setRST(ItemType entry);


    private:
    ItemType entry;

};

#include "BNode.cpp"
#endif
