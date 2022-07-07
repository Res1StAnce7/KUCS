/**
 * @file BST.cpp
 * @author Siliang
 * @brief This file will implement binary search tree
 * @date 2021-04-29
 */
#include <iostream>
#include <stdexcept>
#include "BSTInterface.h"
#include "BNode.h"
using namespace std;

template <typename ItemType, typename KeyType>
BST<ItemType, KeyType>::BST()
{
	m_root = nullptr;
}

template <typename ItemType, typename KeyType>
BST<ItemType, KeyType>::~BST()
{
	delete m_root;
}

//public
template <typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::add(ItemType entry)
{
	if (m_root == nullptr)
	{
		m_root = new BNode<ItemType>(entry);
	}

	else
	{
		recAdd(entry, m_root);
	}
}

//private
template <typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::recAdd(ItemType entry, BNode<ItemType> *subtree)
{
	if (subtree->getEntry() = entry)
	{
		throw(runtime_error("No duplicates allowed!"));
	}

	else if (subtree->getEntry() >= entry)
	{
		if (subtree->getLST() == nullptr)
		{
			BNode<ItemType> *temp = new BNode<ItemType>(entry);
			subtree->setLST(temp);
		}

		else
		{
			recAdd(entry, subtree->getLST());
		}
	}

	else if (subtree->getEntry() <= entry)
	{
		if (subtree->getRST() == nullptr)
		{
			BNode<ItemType> *temp = new BNode<ItemType>(entry);
			subtree->setRST(temp);
		}

		else
		{
			recAdd(entry, subtree->getRST());
		}
	}
}

//public
template <typename ItemType, typename KeyType>
ItemType BST<ItemType, KeyType>::search(KeyType key) const
{
	return (recSearch(key, m_root));
}

//private
template <typename ItemType, typename KeyType>
ItemType BST<ItemType, KeyType>::recSearch(KeyType key, BNode<ItemType> *subtree) const
{
	if (subtree == nullptr)
	{
		throw(runtime_error("Not Found!"));
	}

	else if (subtree->getEntry() == key)
	{
		return (subtree->getEntry());
	}

	else if (subtree->getEntry() > key)
	{
		return recSearch(key, subtree->getLST());
	}

	else if (subtree->getEntry() < key)
	{
		return recSearch(key, subtree->getRST());
	}	
}

//public
template <typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::remove(KeyType key)
{
	if(m_root->getEntry() == key && m_root->getLST() == nullptr && m_root->getRST() == nullptr)
	{
		BNode<ItemType>* temp = m_root;
		m_root = m_root->getLST();
		delete temp;
	}

	else
	{
		recRemove(key, m_root);
	}
	
}

//private
template <typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::recRemove(KeyType key, BNode<ItemType>* subtree)
{
	if(subtree == nullptr)
	{
		throw(runtime_error("The Pokemon is not in the tree!"));
	}

	else if(subtree->getEntry() > key)
	{
		recRemove(key, subtree->getLST());
	}

	else if(subtree->getEntry() < key)
	{
		recRemove(key, subtree->getRST());
	}

	else if(subtree->getEntry() == key)
	{
		if(subtree->getLST() == nullptr && subtree->getRST() == nullptr) // no children
		{
			BNode<ItemType>* parent = nullptr;
			parent = setParent(key, m_root, parent);
			if(parent->getLST() != nullptr)
			{
				if(parent->getLST()->getEntry() == key)
				{
					BNode<ItemType>* temp = subtree;
					subtree = subtree->getLST();
					delete temp;
					parent->setLST(subtree);
				}
			}

			if(parent->getRST() != nullptr)
			{
				if(parent->getRST()->getEntry() == key)
				{
					BNode<ItemType>* temp = subtree;
					subtree = subtree->getRST();
					delete temp;
					parent->setRST(subtree);
				}
			}
		}

		else if(subtree->getLST() != nullptr && subtree->getRST() != nullptr) //two children
		{
			if(subtree == m_root)
			{
				BNode<ItemType>* replace = nullptr;
				replace = recRightMost(m_root->getLST());
				ItemType copy = replace->getEntry();
				BNode<ItemType>* newNode = new BNode<ItemType>(copy);

				BNode<ItemType>* reParent = nullptr;
				reParent = setParent(replace->getEntry().getID(), m_root, reParent);
				BNode<ItemType>* delPtr = replace;
				if(reParent->getLST() != nullptr)
				{
					if(reParent->getLST() == replace)
					{
						replace = replace->getLST();
						delete delPtr;
						reParent->setLST(replace);
					}
				}

				if(reParent->getRST() != nullptr)
				{
					if(reParent->getRST() == replace)
					{
						replace = replace->getRST();
						delete delPtr;
						reParent->setRST(replace);
					}
				}

				newNode->setLST(subtree->getLST());
				newNode->setRST(subtree->getRST());
				delete subtree;
				subtree = newNode;
				m_root = subtree;
			}
			
			else
			{
				BNode<ItemType>* replace = nullptr;
				replace = recRightMost(subtree->getLST());
				ItemType copy = replace->getEntry();
				BNode<ItemType>* newNode = new BNode<ItemType>(copy);

				BNode<ItemType>* reParent = nullptr;
				reParent = setParent(replace->getEntry().getID(), m_root, reParent);
				BNode<ItemType>* delPtr = replace;
				if(reParent->getLST() != nullptr)
				{
					if(reParent->getLST() == replace)
					{
						replace = replace->getLST();
						delete delPtr;
						reParent->setLST(replace);
					}
				}

				if(reParent->getRST() != nullptr)
				{
					if(reParent->getRST() == replace)
					{
						replace = replace->getRST();
						delete delPtr;
						reParent->setRST(replace);
					}
				}
				
				BNode<ItemType>* subParent = nullptr;
				subParent = setParent(subtree->getEntry().getID(), m_root, subParent);
				newNode->setLST(subtree->getLST());
				newNode->setRST(subtree->getRST());
				
				BNode<ItemType>* temp = subtree;
				if(subParent->getLST() != nullptr)
				{
					if(subParent->getLST() == subtree)
					{
						subtree = newNode;
						delete temp;
						subParent->setLST(subtree);
					}
				}

				if(subParent->getRST() != nullptr)
				{
					if(subParent->getRST() == subtree)
					{
						subtree = newNode;
						delete temp;
						subParent->setRST(subtree);
					}
				}
			}
		}

		else // one child
		{
			if(subtree == m_root)
			{
				if(subtree->getLST() != nullptr && subtree->getRST() == nullptr)
				{
					BNode<ItemType>* temp = subtree;
					subtree = subtree->getLST();
					delete temp;
					m_root = subtree;
				}

				else if(subtree->getLST() == nullptr && subtree->getRST() != nullptr)
				{
					BNode<ItemType>* temp = subtree;
					subtree = subtree->getRST();
					delete temp;
					m_root = subtree;
				}
			}

			else
			{
				if(subtree->getLST() != nullptr && subtree->getRST() == nullptr) 
				{
					BNode<ItemType> *subParent = nullptr;
					subParent = setParent(subtree->getEntry().getID(), m_root, subParent);
					BNode<ItemType> *temp = nullptr;
					temp = subtree;

					if(subParent->getLST() != nullptr)
					{
						if(subParent->getLST() == subtree)
						{
							subtree = subtree->getLST();
							delete temp;
							subParent->setLST(subtree);
						}
					}

					if(subParent->getRST() != nullptr)
					{
						if(subParent->getRST() == subtree)
						{
							subtree = subtree->getRST();
							delete temp;
							subParent->setRST(subtree);
						}
					}
				}

				else if(subtree->getLST() == nullptr && subtree->getRST() != nullptr)
				{
					BNode<ItemType> *subParent = nullptr;
					subParent = setParent(subtree->getEntry().getID(), m_root, subParent);
					BNode<ItemType> *temp = nullptr;
					temp = subtree;

					if(subParent->getLST() != nullptr)
					{
						if(subParent->getLST() == subtree)
						{
							subtree = subtree->getLST();
							delete temp;
							subParent->setLST(subtree);
						}
					}

					if(subParent->getRST() != nullptr)
					{
						if(subParent->getRST() == subtree)
						{
							subtree = subtree->getRST();
							delete temp;
							subParent->setRST(subtree);
						}
					}
				}
			}
			
		}
	}
}

//public
template <typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::clear()
{
	recClear(m_root);
}

//private
template <typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::recClear(BNode<ItemType> *subtree) // using post order
{
	if (subtree != nullptr)
	{
		if (subtree->getLST() != nullptr)
		{
			recClear(subtree->getLST());
		}

		if (subtree->getRST() != nullptr)
		{
			recClear(subtree->getRST());
		}

		remove(subtree->getEntry().getID());
	}
}

//public
template <typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::visitPreOrder(void visit(ItemType)) const
{
	recVisitPreOrder(visit, m_root);
}

//private
template <typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::recVisitPreOrder(void visit(ItemType), BNode<ItemType> *subtree) const
{
	if (subtree != nullptr)
	{
		ItemType item = subtree->getEntry();
		visit(item);

		if (subtree->getLST() != nullptr)
		{
			recVisitPreOrder(visit, subtree->getLST());
		}

		if (subtree->getRST() != nullptr)
		{
			recVisitPreOrder(visit, subtree->getRST());
		}
	}

	else
	{
		throw(runtime_error("The tree is empty!"));
	}
}

//public
template <typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::visitInOrder(void visit(ItemType)) const
{
	recVisitInOrder(visit, m_root);
}

//private
template <typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::recVisitInOrder(void visit(ItemType), BNode<ItemType> *subtree) const
{
	if (subtree != nullptr)
	{
		if (subtree->getLST() != nullptr)
		{
			recVisitInOrder(visit, subtree->getLST());
		}

		ItemType item = subtree->getEntry();
		visit(item);

		if (subtree->getRST() != nullptr)
		{
			recVisitInOrder(visit, subtree->getRST());
		}
	}

	else
	{
		throw(runtime_error("The tree is empty!"));
	}
}

//public
template <typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::visitPostOrder(void visit(ItemType)) const
{
	recVisitPostOrder(visit, m_root);
}

//private
template <typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::recVisitPostOrder(void visit(ItemType), BNode<ItemType> *subtree) const
{
	if (subtree != nullptr)
	{
		if (subtree->getLST() != nullptr)
		{
			recVisitPostOrder(visit, subtree->getLST());
		}

		if (subtree->getRST() != nullptr)
		{
			recVisitPostOrder(visit, subtree->getRST());
		}

		ItemType item = subtree->getEntry();
		visit(item);
	}

	else
	{
		throw(runtime_error("The tree is empty!"));
	}
}

template <typename ItemType, typename KeyType>
BNode<ItemType> *BST<ItemType, KeyType>::recLeftMost(BNode<ItemType> *subtree)
{
	while (subtree->getLST() != nullptr)
	{
		subtree = subtree->getLST();
	}
	return subtree;
}

template <typename ItemType, typename KeyType>
BNode<ItemType> *BST<ItemType, KeyType>::recRightMost(BNode<ItemType> *subtree)
{
	while (subtree->getRST() != nullptr)
	{
		subtree = subtree->getRST();
	}
	return subtree;
}

template <typename ItemType, typename KeyType>
BNode<ItemType> *BST<ItemType, KeyType>::setParent(KeyType key, BNode<ItemType> *subtree, BNode<ItemType> *parent)
{
	while (subtree != nullptr && subtree->getEntry() != key)
	{
		parent = subtree;

		if (subtree->getEntry() > key)
		{
			subtree = subtree->getLST();
		}

		else if (subtree->getEntry() < key)
		{
			subtree = subtree->getRST();
		}
	}

	return parent;
}

