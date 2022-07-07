#include <iostream>
#include "Shape.h"
#include "Triangle.h"
using namespace std;

double areaComp(const Shape &a, const Shape &b)
{
    if(a.area() > b.area())
    {
        return(a.area());
    }

    else
    {
        return(b.area());
    }
}

int main()
{

}
