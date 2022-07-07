#ifndef SHAPECONTAINER_H
#define SHAPECONTAINER_H
#include "Shape.h"
#include <stdexcept>
using namespace std;

class ShapeContainer
{
   public:
   ShapeContainer(int size); //initialize pointers in m_arrayOfShapes to nullptr
   ~ShapeContainer();

   /** 
   * @pre 
   * @post return the area of the Shape
   * @throw area
   **/
   double area(int index) const; //throws a runtime_error if index is invalid, meaning out of range OR index has nullptr 

   /** 
   * @pre 
   * @post return the name of the Shape
   * @throw shapeName
   **/
   string shapeName(int index) const; //throws a runtime_error if index is invalid, meaning out of range OR index has nullptr

   /** 
   * @pre 
   * @post add a Shape into the ShapeContainer
   * @throw 
   **/
   void add(Shape* shapePtr, int index); //throws a runtime_error if index is invalid OR if shapePtr is nullptr

   /** 
   * @pre 
   * @post remove a Shape from the ShapeContainer
   * @throw 
   **/
   void remove(int index); //throws a runtime_error if the index is invalid OR there is no object to delete
  
   private:
   Shape** m_arrayOfShapes;
   int m_size;
   int* indexCheck;
   int m_check;
};

#endif