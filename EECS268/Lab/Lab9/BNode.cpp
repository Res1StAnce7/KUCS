/**
 * @file BNode.cpp
 * @author Siliang Zhang
 * @brief This file will implement binary search tree node
 * @date 2021-05-01
 */
#include <iostream>
template <typename ItemType>
BNode<ItemType>::BNode(ItemType entry)
{
	m_entry = entry;
	m_left = nullptr;	
    m_right = nullptr;
}

template <typename ItemType>
ItemType BNode<ItemType>::getEntry() const
{
	return(m_entry);
}

template <typename ItemType>
void BNode<ItemType>::setEntry(ItemType entry)
{
	m_entry = entry;
}

template <typename ItemType>
BNode<ItemType>* BNode<ItemType>::getLST() const
{
	return(m_left);
}

template <typename ItemType>
BNode<ItemType>* BNode<ItemType>::getRST() const
{
	return(m_right);
}

template <typename ItemType>
void BNode<ItemType>::setLST(BNode<ItemType>* left)
{
	m_left = left;
}

template <typename ItemType>
void BNode<ItemType>::setRST(BNode<ItemType>* right)
{
	m_right = right;
}



