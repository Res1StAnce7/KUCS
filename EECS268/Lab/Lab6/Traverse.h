#ifndef TRAVERSE_H
#define TRAVERSE_H
#include <string>
#include "FileReader.h"
using namespace std;

class Traverse
{
    public:
    Traverse(string fileName);

    /** 
    * @pre 
    * @post call the traverse function to walk the maze
    * @throw 
    **/
    void run();

    /** 
    * @pre 
    * @post print the route to walk out of the maze or tell the user there is no way out
    * @throw 
    **/
    void print();

    /** 
    * @pre 
    * @post print the maze info
    * @throw 
    **/
    void mazeInfo();

    /** 
    * @pre start position is valid
    * @post try to walk out of the maze
    * @throw 
    **/
    void traverse(int row, int col, int step);

    /** 
    * @pre 
    * @post set escape to true if success
    * @throw 
    **/
    void setOut(bool escape);

    /** 
    * @pre 
    * @post check if position is valid
    * @throw 
    **/
    bool check(int row ,int col);

    /** 
    * @pre 
    * @post check if we have successfully walked out of the maze
    * @throw 
    **/
    bool Out();

    private:
    FileReader* Reader;
    bool out;
    int num;

};


#endif
