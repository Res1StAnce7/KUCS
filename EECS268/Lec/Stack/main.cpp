#include <iostream>
#include "Node.h"
#include "Stack.h"
using namespace std;
bool isBalanced(char parens[], int size)
{

}

int main()
{
	//Create a heap allocated Node that contains
	//a character
	//T gets defined
	Node<char>* myCharNode = nullptr;
	Node<char>* myCharNode2 = nullptr;
	Node<double>* myDubNode = nullptr;
	
	myCharNode = new Node<char>('Q');
	myCharNode = new Node<char>('R');
	
	myDubNode = new Node<double>(3.14158);
	
	//set the entry to be 'L'
	myCharNode->setEntry('E');
	myCharNode->setNext(myCharNode2);
	
	//ILLEGAL
	//myDubNode->setNext(myCharNode);
	
	//deletes are normal
	delete myCharNode;
	delete myCharNode2;
	delete myDubNode;

    Node<int>* myNum = nullptr;
    Node<int>* myTemp = nullptr;
    myNum = new Node<int>(5);
    myTemp = new Node<int>(10);
    myNum -> setNext(myTemp);
    
    myTemp = new Node<int>(15);
    myNum->getNext()->setNext(myTemp);
    
    cout << myNum->getEntry() << endl;
    cout << myNum->getNext()->getEntry() << endl;
    cout << myNum->getNext()->getNext()->getEntry() << endl;

    delete myNum;
    delete myTemp;
	return(0);
}
