/**
 * @file Circle.cpp
 * @author Siliang Zhang
 * @brief This file will implement the Circle
 * @date 2021-03-15
 */
#include "Circle.h"
#include <math.h>
#define pi 3.1415926

Circle::Circle()
{
    m_radius = 0;
}

Circle::~Circle()
{

}

double Circle::area() const
{
    return(pi * pow(m_radius,2));
}

string Circle::shapeName() const
{
    return{"Circle"};
}

void Circle::set(double radius)
{
    m_radius = radius;
}