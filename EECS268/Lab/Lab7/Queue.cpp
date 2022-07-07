/**
 * @file Queue.cpp
 * @author Siliang Zhang
 * @brief This file will create templated Queue
 * @date 2021-04-11
 */
template <typename T>
Queue<T>::Queue()
{
    m_front = nullptr;
    m_back = nullptr;
}

template <typename T>
Queue<T>::~Queue()
{
    while(!isEmpty())
    {
        dequeue();
    }
}

template <typename T>
void Queue<T>::enqueue(T entry)
{
    if(isEmpty())
	{
        m_back = new Node<T>(entry);
        m_front = m_back;
    }

    else
    {	
        Node<T>* temp = m_back;
        m_back = new Node<T>(entry);
        temp->setNext(m_back);
	}   
}

template <typename T>
Queue<T>::Queue(const Queue<T>& orig)
{
    Node<T>* jumper_q = orig.m_front;

    m_front = nullptr;
    m_back = nullptr; 

    while(jumper_q != nullptr)
    {
        enqueue(jumper_q->getEntry());
        jumper_q = jumper_q->getNext();
    }
}

template <typename T>
void Queue<T>::operator=(const Queue<T>& rhs)
{
    while(!isEmpty())
    {
        dequeue();
    }

    Node<T>* jumper_q = rhs.m_front;
    
    while(jumper_q != nullptr)
    {
        enqueue(jumper_q->getEntry());
        jumper_q = jumper_q->getNext();
    } 
}

template <typename T>
void Queue<T>::dequeue()
{
    if(m_front != nullptr)
    {
        Node<T> *temp = m_front;
        m_front = m_front->getNext();
        delete(temp);
    }
}

template <typename T>
T Queue<T>::peekFront() const
{
    if(!isEmpty())
    {
        return(m_front->getEntry());
    }
}

template <typename T>
bool Queue<T>::isEmpty() const
{
    return(m_front == nullptr);
}