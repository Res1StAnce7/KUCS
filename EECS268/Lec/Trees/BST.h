#ifndef BST_H
#define BST_H
#include "BNode.h"

//ItemType - Type of things in each node (must overload the needed operator)
//KeyType - Type of our search terms
template <typename ItemType, typename KeyType>
class BST
{
	public:
	BST();
    ItemType search(KeyType key) const; 
	void add(ItemType entry);
	void remove(KeyType key);
	

	private:
	BNode<ItemType>* m_root;
	void recAdd(ItemType entry, BNode<ItemType>* subtree);
	ItemType recSearch(KeyType key, BNode<ItemType>* subtree) const; 
};

#include "BST.cpp"
#endif 

//Start at the root
//given a value to ad to a subtree
//compare against the value in the current subtree's node
//if the new value is less than the root's value, add it to the left subtree
//if the new value is greater that the root's value, add it to the right subtree tree
//NO DUPLICATE VALUE ALLOWED (throw an exception)
//if the subtree is empty, add the value

//Search in O(log 2 n) time

//Uses of traversal Orders
//Pre: Visit-GO LST-GO RST
//In: GO LST-Visit-Go RST
//Post: GO LST-Go Rst-Visit
//For all binary trees, post order is great for destructors