#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
    public:
    //area is a pure virtual method
    //不能被实例化，只能被继承
    //抽象方法必须在子类继承
    virtual double area() const = 0;



    private:
};

#endif