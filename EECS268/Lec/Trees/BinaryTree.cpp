#include "BNode.h"
template<typename ItemType>
BinaryTree<ItemType>::BinaryTree()
{
    m_root = nullptr;
}

//public search
template <typename ItemType>
bool BinaryTree<ItemType>::search(ItemType target) const
{
    return(recSearch(target, m_root));
}

//private search
template <typename ItemType>
bool BinaryTree<ItemType>::recSearch(ItemType target, BNode<ItemType>* subtree) const
{
    if(subtree == nullptr)
    {
        return false; //empty
    }

    else if(subtree->getEntry() == target)
    {
        return true; //found
    }

    else
    {
        //search both subtrees
        bool isInLST = recSearch(target,subtree->getLeft());
        bool isInRST = recSearch(target,subtree->getRight());
        return(isInLST || isInRST);
    }
}

//public countNodes
template <typename ItemType>
int BinaryTree<ItemType>::countNodes() const
{
    return recCountNodes(m_root);
}

//private countNodes
template <typename ItemType>
int BinaryTree<ItemType>::recCountNodes(BNode<ItemType>* subtree) const
{
    if(subtree == nullptr)
    {
        return 0;
    }

    else
    {
        return recCountNodes(subtree->getLeft())+recCountNode(subtree->getRight())+1;
    }
}
