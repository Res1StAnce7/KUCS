#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shape.h"

class Triangle : public Shape
{
    public:
    Triangle(double base, double height);
    double area() const;

    private:
    double base;
	double height;


};

#endif
