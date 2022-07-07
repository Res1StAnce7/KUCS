#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"

class Circle : public Shape
{
    public:
    Circle();
    ~Circle();

    /** 
    * @pre 
    * @post return the area of the Circle
    * @throw area
    **/
    double area() const;

    /** 
    * @pre 
    * @post return the name of the Circle
    * @throw circleName
    **/
    string shapeName() const;

    /** 
    * @pre 
    * @post set the radius for the Circle
    * @throw 
    **/
    void set(double radius);

    private:
    double m_radius;

};


#endif 