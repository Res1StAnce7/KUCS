#ifndef BST_H
#define BST_H
#include "BSTInterface.h"
#include "BNode.h"

template <typename ItemType, typename KeyType>
class BST : public BSTInterface<ItemType, KeyType>
{
	public:
	BST();
    ~BST();

	/** 
    * @pre 
    * @post set the tree
    * @throw  throw std::suntime_error if the tree is empty
    **/
    ItemType search(KeyType key) const; 

	/** 
    * @pre 
    * @post add to the tree
    * @throw  throw std::suntime_error if the tree is empty
    **/
	void add(ItemType entry);

	/** 
    * @pre the tree is not empty
    * @post remove form the tree
    * @throw  throw std::suntime_error if the tree is empty
    **/
	void remove(KeyType key);

	/** 
    * @pre 
    * @post empty the tree
    * @throw  
    **/
	void clear();

	/** 
    * @pre the tree is not empty
    * @post visit the tree using pre order
    * @throw  throw std::suntime_error if the tree is empty
    **/
	void visitPreOrder(void visit(ItemType)) const;

	/** 
    * @pre the tree is not empty
    * @post visit the tree using in order
    * @throw  throw std::suntime_error if the tree is empty
    **/
	void visitInOrder(void visit(ItemType)) const;

	/** 
    * @pre the tree is not empty
    * @post visit the tree using post order
    * @throw  throw std::suntime_error if the tree is empty
    **/
	void visitPostOrder(void visit(ItemType)) const;

	/** 
    * @pre the tree is not empty
    * @post set the parent pointer
    * @throw  
    **/
	BNode<ItemType>* setParent(KeyType key, BNode<ItemType>* subtree, BNode<ItemType>* parent);

	protected:
	BNode<ItemType>* m_root;
	void recAdd(ItemType entry, BNode<ItemType>* subtree);
	ItemType recSearch(KeyType key, BNode<ItemType>* subtree) const;
	void recVisitPreOrder(void visit(ItemType), BNode<ItemType>* subtree) const;
	void recVisitInOrder(void visit(ItemType), BNode<ItemType>* subtree) const;
	void recVisitPostOrder(void visit(ItemType), BNode<ItemType>* subtree) const;
	void recRemove(KeyType key, BNode<ItemType>* subtree);
	BNode<ItemType>* recLeftMost(BNode<ItemType>* subtree);
	BNode<ItemType>* recRightMost(BNode<ItemType>* subtree);
	void recClear(BNode<ItemType>* subtree);
};

#include "BST.cpp"
#endif 
