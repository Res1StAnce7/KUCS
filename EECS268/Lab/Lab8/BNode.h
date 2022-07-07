#ifndef BNODE_H
#define BNODE_H

template <typename ItemType>
class BNode
{
	public:
	BNode(ItemType entry);

	/** 
    * @pre 
    * @post get the entry
    * @return entry
    **/
	ItemType getEntry() const;

	/** 
    * @pre 
    * @post set the entry
    * @throw   
    **/
	void setEntry(ItemType entry);

	/** 
    * @pre 
    * @post get the left node
    * @throw   
    **/
	BNode<ItemType>* getLST() const;

    /** 
    * @pre 
    * @post get the right node
    * @throw   
    **/
    BNode<ItemType>* getRST() const;

	/** 
    * @pre 
    * @post set the left node
    * @throw   
    **/
	void setLST(BNode<ItemType>* left);

    /** 
    * @pre 
    * @post set the right node
    * @throw   
    **/
    void setRST(BNode<ItemType>* right);
    
   

    private:
	ItemType m_entry;	
    BNode<ItemType>* m_left;
    BNode<ItemType>* m_right;
   
    
};

#include "BNode.cpp"
#endif