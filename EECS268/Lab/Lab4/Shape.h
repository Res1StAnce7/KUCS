#ifndef SHAPE_H
#define SHAPE_H
#include <string>
using namespace std;

class Shape
{
   public:

   /** 
   * @pre 
   * @post pure virtual area() function
   * @throw 
   **/
   virtual double area() const = 0;

   /** 
   * @pre 
   * @post pure virtual area() function
   * @throw 
   **/
   virtual string shapeName() const = 0;

   /** 
   * @pre 
   * @post pure virtual Shape destructor
   * @throw 
   **/
   virtual ~Shape() {}
};

#endif 
