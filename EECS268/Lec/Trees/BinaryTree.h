#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "BNode.h"

template <typename ItemType>
class BinaryTree
{
    public:
    BinaryTree(); //Set m_root to nullptr
    void add(ItemType entry);
    bool search(ItemType target) const; //return true if the entry is in the tree
    int countNodes() const; //return the count of Nodes in the entire tree

    private:
    BNode<ItemType>* m_root;
    bool recSearch(ItemType target, BNode<ItemType>* subtree) const;
    int recCountNodes(BNode<ItemType>* subtree) const;
};

#include "BinaryTree.cpp"
#endif 
