#include <iostream>
#include "Animal.h"
using namespace std;

Animal::Animal(int age)
{
    m_age = age;
    m_IsHungry = true;
}

int Animal::getAge() const
{
    return(m_age);
}

bool Animal::checkHungry() const
{
    return(m_IsHungry);
}

void Animal::sleep()
{
    cout << "Animal sleeping..." << endl;
}