#include <iostream>
#include "Circle.h"
#include "CircleDriver.h"
using namespace std;

void CircleDriver::obtainCircles()
{
    double x, y, r;

    cout << "Enter information for Circle 1: \n";
    cout << "Radius: ";
    cin >> r;
    cout << "X Position: ";
    cin >> x;
    cout << "Y Position: ";
    cin >> y;
    circ1.setX(x);
    circ1.setY(y);
    circ1.setRadius(r);

    cout << "\nEnter information for Circle 2: \n";
    cout << "Radius: ";
    cin >> r;
    cout << "X Position: ";
    cin >> x;
    cout << "Y Position: ";
    cin >> y;
    circ2.setX(x);
    circ2.setY(y);
    circ2.setRadius(r);
}

void CircleDriver::printCircleInfo()
{
    cout << "\nInformation for Circle 1: " << '\n';
    cout << "location: (" << circ1.getX() << "," << circ1.getY() << ")" << '\n';
    cout << "diameter: " << circ1.diameter() << "" << '\n';
    cout << "area: " << circ1.area() << "" << '\n';
    cout << "circumference: " << circ1.circumference() << "" << '\n';
    cout << "distance from the origin: " << circ1.distanceToOrigin() << "" << '\n';

    cout << "\nInformation for Circle 2: " << '\n';
    cout << "location: (" << circ2.getX() << "," << circ2.getY() << ")" << '\n';
    cout << "diameter: " << circ2.diameter() << "" << '\n';
    cout << "area: " << circ2.area() << "" << '\n';
    cout << "circumference: " << circ2.circumference() << "" << '\n';
    cout << "distance from the origin: " << circ2.distanceToOrigin() << "" << '\n';

    if (circ1.intersect(circ2))
    {
        cout << "\nThe circles intersect." << '\n';
    }
    else
    {
        cout << "\nThe circles do not intersect." << '\n';
    }
}

void CircleDriver::run()
{
    obtainCircles();
    printCircleInfo();
}