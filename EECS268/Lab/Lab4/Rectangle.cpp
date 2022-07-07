/**
 * @file Rectangle.cpp
 * @author Siliang Zhang
 * @brief This file will implement the Rectangle
 * @date 2021-03-15
 */
#include "Rectangle.h"

Rectangle::Rectangle()
{
    m_length = 0;
    m_width = 0;
}

Rectangle::~Rectangle()
{

}

double Rectangle::area() const
{
    return(m_length * m_width);
}

string Rectangle::shapeName() const
{
    return{"Rectangle"};
}

void Rectangle::set(double length, double width)
{
    m_length = length;
    m_width = width;
}