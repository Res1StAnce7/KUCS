#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"

class Rectangle : public Shape
{
    public:
    Rectangle();
    ~Rectangle();

    /** 
    * @pre 
    * @post return the area of the Rectangle
    * @throw area
    **/
    double area() const;

    /** 
    * @pre 
    * @post return the name of the Rectangle
    * @throw rectangleName
    **/
    string shapeName() const;

     /** 
    * @pre 
    * @post set length and width for the Rectangle
    * @throw
    **/
    void set(double length, double width);

    private:
    double m_length;
    double m_width;
};

#endif 
