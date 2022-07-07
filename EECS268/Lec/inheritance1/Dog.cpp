//Dog,cpp
#include <iostream>
#include "Animal.h"
#include "Dog.h"
using namespace std;
                   
Dog::Dog(int age) : Animal::Animal(age)
{
    cout << " Dog is constructed!" << endl;
    m_IsHungry = false;
}

void Dog::doTrick()
{
	std::cout << "Dog is rolling over\n";
}

void Dog::sleep()
{
	std::cout << "Rup. Rup. Rup-up\n";
}