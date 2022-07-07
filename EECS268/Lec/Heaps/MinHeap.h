#ifndef MINHEAP_H
#define MINHEAP_H
using namespace std;

template <typename T>
class MinHeap
{
    public:
    void add(T entry);
    void remove(T entry);
    

    private:
    T* m_array;
    int m_arraySize;
    int m_heapSize;
    int leftChild(int index);
    void resize();
    void upheap(int index);
    void downheap(int index);
    
};

#include "MinHeap.cpp"
#endif 


