#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shape.h"

class Triangle : public Shape
{
    public:
    Triangle();
    ~Triangle();
    
    /** 
    * @pre 
    * @post return the area of the Triangle
    * @throw area
    **/
    double area() const;

    /** 
    * @pre 
    * @post return the name of the Triangle
    * @throw triangleName
    **/
    string shapeName() const;

    /** 
    * @pre 
    * @post set base and height for the Triangle
    * @throw 
    **/
    void set(double base, double height);

    private:
    double m_base;
	double m_height;


};

#endif
