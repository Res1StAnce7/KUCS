#ifndef CIRCLE_H
#define CIRCLE_H

class Circle
{
    public:
        Circle();
        double diameter();
        double area();
        double circumference();
        double distanceToOrigin();
        bool intersect(Circle otherCircle);
        double getRadius();
        double getX();
        double getY();
        void setRadius(double r);
        void setX(double x);
        void setY(double y);

    private:
        double radius;
        double xPos;
        double yPos;
};

#endif