#include <iostream>
#include "MinHeap.h"
using namespace std;

int main()
{

    return 0;
}

//Heaps (top to bottom, left to right)
//Special form of a Binary Tree: Complete
//A complete binary tree is filled in level by level from left to right
//min-heap 
//every nodes value is less than or equal both of its children (small-large)
//max-heap
//every nodes value is greater than or equal both of its children (large-small)

//min-heap
//Adding to min heap
//-Preserve completness and the order of the values(add the new node to left-most unfill position in the tree)
//unheap: comprae against parent and swap if needed reapeat as needed
//Space: log 2 n

//Remove: 
//-always remove the root
//-replace the root with lowest, right-most node
//-down heap the new root
//--comprare against the min of the children, swap (repeat) if needed

//Implement a Binary Tress using an array
//root:0 / left child of i: 2i+1 / right child of i: 2i+2 / parent of i: (i-1)/2
//child: i / parent (i-1)/2

//remove: 

//index where we always add new value: heapSize
//index of temporary root: heapSize-1


//heap sort
//1 heapify
//2 remove all values (ascending)-max heap  decending-min heap
//Time Complexity: O(n(log 2 n)) 
//                 1) heapifying the array: 
//                  -adding 1 value : O(log 2 n) 
//                   -Place in the lowest: O(1) / Unheap the value: O(log 2 n) 
//                  -adding n value: O(n(log 2 n)) 
//                 2) removing all value:
//                  -removing 1 value:
//                   -Swap root with lowest right-most node:  O(1)
//                   -downheap temp root: O(log 2 n) 
//                  -removing n value: O(n(log 2 n)) 
//Space Complexity:
//-Iterative(loops): O(1)
//-Recursive: O(log 2 n) 