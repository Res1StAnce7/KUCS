/**
 * @file Node.cpp
 * @author Siliang Zhang
 * @brief This file will create templated Node
 * @date 2021-04-11
 */
template <typename T>
Node<T>::Node(T entry)
{
	m_entry = entry;
	m_next = nullptr;
}

template <typename T>
T Node<T>::getEntry() const
{
	return(m_entry);
}

template <typename T>
void Node<T>::setEntry(T entry)
{
	m_entry = entry;
}

template <typename T>
Node<T>* Node<T>::getNext() const
{
	return(m_next);
}

template <typename T>
void Node<T>::setNext(Node<T>* next)
{
	m_next = next;
}