#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include <string>
#include "Pokemon.h"
#include "BST.h"
using namespace std;

class Executive
{
    public:
    Executive(string fileName);

    /** 
    * @pre 
    * @post run the show
    * @throw  
    **/
    void run();

    /** 
    * @pre 
    * @post read the file
    * @throw  
    **/
    bool read();

    /** 
    * @pre 
    * @post load the Pokemon info into the tree
    * @throw  
    **/
    bool load();

    /** 
    * @pre 
    * @post free the alllocated memory and delete pointers
    * @throw  
    **/
    void clear();

    /** 
    * @pre 
    * @post print the BST menu
    * @throw  
    **/
    void BST_Menu();

    /** 
    * @pre 
    * @post print the traversal orders
    * @throw  
    **/
    void T_Order();

    /** 
    * @pre 
    * @post store the Pokemon info
    * @throw  
    **/
    void addPoke(string usa, int id, string jap);

    /** 
    * @pre 
    * @post print the Pokemon info
    * @throw  
    **/
    static void visit(Pokemon p);

    private:
    Pokemon** Pokedex;
    BST<Pokemon,int>* tree;
    string* usa;
    string* jap;
    int* id;
    string m_fileName;
    int m_size;
    

};

#endif 
