#ifndef ANIMAL_H
#define ANIMAL_H

class Animal //Base class
{
    public:
    Animal(int age);
    int getAge() const;
    bool checkHungry() const;
    virtual void sleep();

    protected:
    int m_age;
    bool m_IsHungry;

};

#endif