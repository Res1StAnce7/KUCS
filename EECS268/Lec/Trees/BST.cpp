#include <stdexcept>
#include "BNode.h"
//public search
template <typename ItemType, typename KeyType>
ItemType BST<ItemType, KeyType>::search(KeyType key) const
{
	return recSearch(key, m_root);
}

//private
template <typename ItemType, typename KeyType>
ItemType BST<ItemType, KeyType>::recSearch(KeyType key, BNode<ItemType>* subtree) const
{
	//Board work: finish this definition
	//Assume that ItemType == KeyType
	//				ItemType < KeyType
	//				ItemType > KeyType
	//			are all defined-
	if(subtree == nullptr)
	{
		throw(runtime_error("The subtree is empty!"));
	}

	else if(subtree->getEntry() == key)
	{
		return(subtree->getEntry();)
	}

	else if(subtree->getEntry() > key)
	{
		//go right
	}

	else 
	{
		//go left
	}

}

//public
template <typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::add(ItemType entry)
{
	if(m_root == nullptr)
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
void BST<ItemType, KeyType>::recAdd(ItemType entry, BNode<ItemType>* subtree)
{
	//subtree pointer will always be pointing to a BNode object

	//Base case 1: entry: entry matched the current node's entry
	//Base case 2&3: The entry should be added to LST/RST and that subtree is empty then just add the new entry
	//Recursive case: Go into appropriate subtree
	if(subtree->getEntry() == entry)
	{
		throw(runtime_error("No duplicates allowed!"));
	}

	else if(subtree->getEntry() > entry)
	{
		if(subtree->getLST() == nullptr)
		{
			BNode<ItemType>* temp = new BNode<ItemType>(entry);
			subtree->setLST(temp);
		}

		else
		{
			recAdd(entry,subtree->getLST());
		}
	}

	else if(subtree->getEntry() < entry)
	{
		if(subtree->getRST() == nullptr)
		{
			BNode<ItemType>* temp = new BNode<ItemType>(entry);
			subtree->setRST(temp);
		}

		else
		{
			recAdd(entry,subtree->getRST());
		}
	}
}

template <typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::remove(KeyType key)
{
	//Case 1 (no children): delete the node and set the pointer to null
	//Case 2 (one child): remove the target node and parent points to the only child
	//Case 3 (two children): find a replacement which have a spare point and be able to preserve the structure
	//                       pick the max from LST or min from the RST
	//						 perform a remove on that candidate and replace the target

}