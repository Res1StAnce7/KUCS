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
    * @post visit the tree using pre-order
    * @throw  throw std::suntime_error if the tree is empty
    **/
	void visitPreOrder(void visit(ItemType)) const;

	/** 
    * @pre the tree is not empty
    * @post visit the tree using in-order
    * @throw  throw std::suntime_error if the tree is empty
    **/
	void visitInOrder(void visit(ItemType)) const;

	/** 
    * @pre the tree is not empty
    * @post visit the tree using post-order
    * @throw  throw std::suntime_error if the tree is empty
    **/
	void visitPostOrder(void visit(ItemType)) const;

	/** 
    * @pre the tree is not empty
    * @post set the parent pointer
    * @throw  
    **/
	BNode<ItemType>* setParent(KeyType key, BNode<ItemType>* subtree, BNode<ItemType>* parent);

	/** 
    * @pre 
    * @post call the recursive copy function to copy the tree
    * @throw  
    **/
	void copyBST();

	/** 
    * @pre 
    * @post set the tree for operatoon
    * @throw  
    **/
	void which(int selection);

	/** 
    * @pre 
    * @post set the tree status
    * @throw  
    **/
	void created();

	protected:
	BNode<ItemType>* m_root;
	BNode<ItemType>* m_copy;

	/** 
    * @pre 
    * @post recursive add
    * @throw  
    **/
	void recAdd(ItemType entry, BNode<ItemType>* subtree);

	/** 
    * @pre the tree is not empty
    * @post recursive search
    * @throw  
    **/
	ItemType recSearch(KeyType key, BNode<ItemType>* subtree) const;

	/** 
    * @pre the tree is not empty
    * @post recursive visit using in-order
    * @throw  
    **/
	void recVisitPreOrder(void visit(ItemType), BNode<ItemType>* subtree) const;

	/** 
    * @pre the tree is not empty
    * @post recursive visit using in-order
    * @throw  
    **/
	void recVisitInOrder(void visit(ItemType), BNode<ItemType>* subtree) const;

	/** 
    * @pre the tree is not empty
    * @post recursive visit using in-order
    * @throw  
    **/
	void recVisitPostOrder(void visit(ItemType), BNode<ItemType>* subtree) const;

	/** 
    * @pre the tree is not empty
    * @post recursive remove
    * @throw  
    **/
	void recRemove(KeyType key, BNode<ItemType>* subtree);

	/** 
    * @pre 
    * @post get the left-most pointer
    * @throw  
    **/
	BNode<ItemType>* recLeftMost(BNode<ItemType>* subtree);

	/** 
    * @pre 
    * @post get the right-most pointer
    * @throw  
    **/
	BNode<ItemType>* recRightMost(BNode<ItemType>* subtree);

	/** 
    * @pre 
    * @post recursive clear
    * @throw  
    **/
	void recClear(BNode<ItemType>* subtree);

	/** 
    * @pre 
    * @post recursive copy the tree using pre-order
    * @throw  
    **/
	void recCopyBST(BNode<ItemType>* origin);
	int m_select;
	bool m_create;
};

#include "BST.cpp"
#endif 
