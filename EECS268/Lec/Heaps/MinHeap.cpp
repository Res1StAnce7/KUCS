template <typename T>
void MinHeap<T>::add(T entry)
{
    if(m_heapSize == m_arraySize)
    {
        resize();
    }

    m_arr[m_heapSize] = entry;
    upheap(m_heapSize);
    m_heapSize++;
}

template <typename T>
void MinHeap<T>::upheap(int index)
{
    if(m_array[index] < m_array[(index - 1) / 2])
    {
        T temp = m_array[(index - 1) / 2];
        m_array[(index - 1) / 2] = m_array[index];
        m_array[index] = temp;
        unpheap((index - 1) / 2);
    }
}

template <typename T>
void MinHeap<T>::downheap(int index)
{
    if(m_array[index] < m_array[(index*2)+1] && m_array[index] > m_array[(index*2)+2])
    {
        T temp = m_array[(index*2)+1];
        m_array[(index*2)+1] = array[index];
        m_array[index] = temp;
        downheap((index*2)+1);
    }

    else if(m_array[index] > m_array[(index*2)+1] && m_array[index] < m_array[(index*2)+2])
    {
        T temp = m_array[(index*2)+2];
        m_array[(index*2)+2] = array[index];
        m_array[index] = temp;
        downheap((index*2)+2);
    }

    else if(m_array[index] < m_array[(index*2)+1] && m_array[index] < m_array[(index*2)+2])
    {
        if(m_array[(index*2)+1] > m_array[(index*2)+2])
        {
            T temp = m_array[(index*2)+1];
            m_array[(index*2)+1] = array[index];
            m_array[index] = temp;
            downheap((index*2)+1);
        }

        else
        {
            T temp = m_array[(index*2)+2];
            m_array[(index*2)+2] = array[index];
            m_array[index] = temp;
            downheap((index*2)+2);
        }
    }
}