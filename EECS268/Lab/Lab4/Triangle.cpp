/**
 * @file Triangle.cpp
 * @author Siliang Zhang
 * @brief This file will implement the Triangle
 * @date 2021-03-15
 */
#include "Triangle.h"

Triangle::Triangle()
{
    m_base = 0;
    m_height = 0;
}

Triangle::~Triangle()
{

}

double Triangle::area() const
{
    return(0.5 * m_base * m_height);
}

string Triangle::shapeName() const
{
    return{"Triangle"};
}

void Triangle::set(double base, double height)
{
    m_base = base;
    m_height = height;
}

