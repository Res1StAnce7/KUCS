#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "Shape.h"
#include "ShapeContainer.h"
using namespace std;

class Executive
{
    public:
    Executive(string lineCommand);

    /** 
    * @pre 
    * @post run the show
    * @throw 
    **/
    void run();

    /** 
    * @pre 
    * @post check if radius is valid
    * @throw 
    **/
    bool isValid_Cir(double radius);

    /** 
    * @pre 
    * @post check if base and height are valid
    * @throw 
    **/
    bool isValid_Tri(double base, double height);

    /** 
    * @pre 
    * @post check if length and width are valid
    * @throw 
    **/
    bool isValid_Rec(double length, double width);

    private:
    string m_filename;
    int m_sizeOfContainer;
};

#endif 
