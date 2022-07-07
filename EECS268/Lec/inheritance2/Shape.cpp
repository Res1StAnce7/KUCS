#include "Shape.h"
#include "Triangle.h"

double Shape::area() const
{

}

int main()
{
    /*Shape myShape;*/ //illegal
    Shape* shapePtr = nullptr;
    shapePtr = new Triangle(5,10);

    /*Shape* shapeCollection[55]*/ //illegal
    Shape* shapeCollection[55];
}