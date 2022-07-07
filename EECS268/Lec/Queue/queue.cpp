template <typename T>
Queue<T>::Queue()
{
    m_front = nullptr;
    m_back = nullptr;
}

template <typename T>
Queue<T>::~Queue()
{

}

template <typename T>
void Queue<T>::enqueue(T entry)
{
    //empty stack
    if(isEmpty())
	{
        m_back = new Node<T>(entry);
        m_front = new Node<T>(entry);
    }

    //non-empty stack
    else
    {	
        Node<T>* temp = m_back;
        m_back = new Node<T>(entry);
        temp->seNext(m_back);
	}   
}

template <typename T>
Queue<T>::Queue(const Queue<T>& orig)
{
    Node<T>* jumper = orig.m_front;

    m_front = nullptr; // A different instructor
    m_back = nullptr;  // Initialization required

    while(jumper != nullptr)
    {
        enqueue(jumper->getEntry());
        jumper = jumper->getNext();
    }
}

template <typename T>
void Queue<T>::operator=(const Queue<T>& rhs)
{
    while(!isEmpty())
    {
        dequeue();
    }

    Node<T>* jumper = rhs.m_front;
    
    while(jumper != nullptr)
    {
        enqueue(jumper->getEntry());
        jumper = jumper->getNext();
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
    return(m_front);
}

template <typename T>
bool Queue<T>::isEmpty() const
{
    return(m_front=nullptr);
}


