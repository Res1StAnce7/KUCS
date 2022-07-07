#ifndef FILEREADER_H
#define FILEREADER_H
#include <string>
using namespace std;

class FileReader
{
    public:
    FileReader(string fileName);
    ~FileReader();

    /** 
    * @pre 
    * @post check if the maze file is valid and store the info in the file
    * @throw 
    **/
    bool read();

    /** 
    * @pre 
    * @post return the certian value of the maze
    * @throw 
    **/
    char getInfo(int row, int col);

    /** 
    * @pre 
    * @post return the order of the step of walking out of the maze
    * @throw 
    **/
    int traverseOPT(int row, int col);

    /** 
    * @pre 
    * @post set the order of the step of walking out of the maze
    * @throw 
    **/
    void setOPT(int row, int col, int value);

    /** 
    * @pre 
    * @post set the position of the maze visited or not visited
    * @throw 
    **/
    void setVisited(int row, int col, bool value);

    /** 
    * @pre 
    * @post check a certain position of the maze is visited or not
    * @throw 
    **/
    bool getVisited(int row, int col);

    /** 
    * @pre 
    * @post return the total row
    * @throw 
    **/
    int getNR();

    /** 
    * @pre 
    * @post return the total column
    * @throw 
    **/
    int getNC();

    /** 
    * @pre 
    * @post return the starting row
    * @throw 
    **/
    int getSR();

    /** 
    * @pre 
    * @post return the starting column
    * @throw 
    **/
    int getSC();

    private:
    string m_fileName;
    char** maze;
    int** mazeOPT;
    bool** visited;
    int nR, nC, sR, sC;
};

#endif