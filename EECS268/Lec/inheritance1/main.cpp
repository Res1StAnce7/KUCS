#include <iostream>
#include "Animal.h"
#include "Dog.h"
using namespace std;

//An Animal& or Animal* only has access to Animal methods
void printAnimal(Animal& a)
{  
    cout << "age = " << a.getAge() << endl;
    cout << "hungry? = " << a.checkHungry() << endl;   
    a.sleep(); //polymorphism ¶àÌ¬ÐÔ
}

int main()
{
    Animal myAnimal(7);
    Dog myDog(12);

    //myAnimal.doTrick()
    myDog.doTrick();
	myDog.sleep();

    printAnimal(myAnimal);
    printAnimal(myDog);

    return 0;
}