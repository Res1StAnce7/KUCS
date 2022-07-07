#include "Circle.h"
#ifndef CIRCLEDRIVER_H
#define CIRCLEDRIVER_H

class CircleDriver{
    
    public:
        void run();

    private:
        Circle circ1;
        Circle circ2;
        void obtainCircles();
        void printCircleInfo();

};

#endif