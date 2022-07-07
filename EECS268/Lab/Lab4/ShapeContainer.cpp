/**
 * @file ShapeContainer.cpp
 * @author Siliang Zhang
 * @brief This file will contian certain amounts of Shapes
 * @date 2021-03-15
 */
#include <stdexcept>
#include "ShapeContainer.h"
#include "Shape.h"

ShapeContainer::ShapeContainer(int size)
{
    m_arrayOfShapes = new Shape*[size];
    indexCheck = new int[size];
    for(int i=0; i<size; i++)
    {
        indexCheck[i] = size + 1;
    }
    m_size = size;
    m_check = 0;
}

ShapeContainer::~ShapeContainer()
{
    if(m_arrayOfShapes != nullptr)
    {
        delete[] m_arrayOfShapes;
    }

    if(indexCheck != nullptr)     
    {
        delete[] indexCheck;
    }
}

double ShapeContainer::area(int index) const
{
    bool check = false;
    if(index >= 0 && index <= m_size)
    {
        for(int i=0; i<m_size; i++)
        {
            if(indexCheck[i] == index)
            {
                check = true;
            }
        }

        if(check == true)
        {
            return(m_arrayOfShapes[index]->area());
        }

        else
        {
            throw runtime_error("Does not exist");
        }
    }

    else
    {
        throw runtime_error("Does not exist");
    }  
}

string ShapeContainer::shapeName(int index) const
{
    bool check = false;
    if(index >= 0 && index <= m_size)
    {
        for(int i=0; i<m_size; i++)
        {
            if(indexCheck[i] == index)
            {
                check = true;
            }
        }

        if(check == true)
        {
            return(m_arrayOfShapes[index]->shapeName());
        }

        else
        {
            throw runtime_error("Does not exist");
        }
    }

    else
    {
        throw runtime_error("Does not exist");
    }
}

void ShapeContainer::add(Shape* shapePtr, int index)
{
    if(index >= 0 && index <= m_size && shapePtr != nullptr)
    {
        m_arrayOfShapes[index] = shapePtr;
        indexCheck[m_check] = index;
        m_check++;
    }

    else
    {
        throw runtime_error("Does not exist");
    }  
}

void ShapeContainer::remove(int index)
{
    bool check = false;
    if(index >= 0 && index <= m_size)
    {
        for(int i=0; i<m_size; i++)
        {
            if(indexCheck[i] == index)
            {
                check = true;
            }
        }

        if(check == true)
        {
            m_arrayOfShapes[index] = nullptr;

            for(int i=0; i<m_size; i++)
            {
                if(indexCheck[i] == index)
                {
                    indexCheck[i] = m_size + 1;
                }
            }
        }

        else
        {
            throw runtime_error("Does not exist");
        }
    }

    else
    {
        throw runtime_error("Does not exist");
    }
}