template <typename T>
Stack<T>::Stack()
{
	m_top = nullptr;
}

template <typename T>
bool Stack<T>::isEmpty() const
{
	return(m_top = nullptr);
}

template <typename T>
void Stack<T>::push(T entry) 
{
	//empty stack
    if(isEmpty())
	{
        m_top = new Node<T>(entry);
    }

    //non-empty stack
    else{
		//get another pointer to the point
		//at the top node
	    Node<T>* temp = m_top;

		//use top to point a new node with the new entry
	    m_top= new Node<T>(entry);

		//connect the new top to the node
	    m_top->setNext(temp);
	}   
}

template <typename T>
void Stack<T>::pop()
{

}

template <typename T>
T Stack<T>::peek() const
{
    if(!isEmpty())
	{
		return(m_top->getEntry());	
	}
	else
	{
		//returning isn't an option
		throw(runtime_error("Peek called on empty stack"));
	}
}
