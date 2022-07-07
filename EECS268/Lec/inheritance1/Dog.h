#ifndef DOG_H
#define DOG_H
#include "Animal.h"

//sub class
class Dog : public Animal  //inherits from Animal
{
    public:
    Dog(int age); 
    void doTrick();
    virtual void sleep();
};

#endif