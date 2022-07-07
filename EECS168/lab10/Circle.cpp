#include "Circle.h"
#include <math.h>
#define Pi 3.1415926535879323846

Circle::Circle(){
    xPos = 0;
    yPos = 0;
    radius = 0;
}

double Circle::getRadius(){
    return(radius);
}

double Circle::getX(){
    return(xPos);
}

double Circle::getY(){
    return(yPos);
}

void Circle::setX(double x){
    xPos = x;
}

void Circle::setY(double y){
    yPos = y;
}

void Circle::setRadius(double r){
    radius = r;
}

double Circle::diameter(){
    return(2 * radius);
}

double Circle::area(){
    return(Pi * pow(radius,2));
}

double Circle::circumference(){
    return(2 * Pi * radius);
}

double Circle::distanceToOrigin(){
    return(sqrt(pow(xPos,2) + pow(yPos,2)));
}

bool Circle::intersect(Circle otherCircle){
    double dist1 = sqrt((pow((xPos - otherCircle.xPos),2))+(pow((yPos - otherCircle.yPos),2)));
    double dist2 = radius + otherCircle.radius;

    if(dist1 > dist2){

        return(false);
    }

    else{

        return(true);
    }
}



