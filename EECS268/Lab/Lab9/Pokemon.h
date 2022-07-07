#ifndef POKEMON_H
#define POKEMON_H
#include "BNode.h"
#include <string>
using namespace std;

class Pokemon
{
    public:
    Pokemon();
    ~Pokemon();

    /** 
    * @pre 
    * @post store the Pokemon name using in the USA
    * @throw  
    **/
    void setUSA(string name);

    /** 
    * @pre 
    * @post store the Pokemon iid
    * @throw  
    **/
    void setID(int id);

    /** 
    * @pre 
    * @post store the Pokemon name using in Japan
    * @throw  
    **/
    void setJAP(string name);

    /** 
    * @pre 
    * @post compare ids
    * @throw  
    **/
    bool operator==(int id);

    /** 
    * @pre 
    * @post compare ids
    * @throw  
    **/
    bool operator>(int id);

    /** 
    * @pre 
    * @post compare ids
    * @throw  
    **/
    bool operator<(int id);

    /** 
    * @pre 
    * @post compare ids
    * @throw  
    **/
    bool operator!=(int id);

    /** 
    * @pre 
    * @post compare ids
    * @throw  
    **/
    bool operator==(Pokemon Poke);

    /** 
    * @pre 
    * @post compare ids
    * @throw  
    **/
    bool operator>(Pokemon Poke);

    /** 
    * @pre 
    * @post compare ids
    * @throw  
    **/
    bool operator<(Pokemon Poke);

    /** 
    * @pre 
    * @post return the Pokemon name using in the USA
    * @throw  
    **/
    string getUSA();

    /** 
    * @pre 
    * @post return the Pokemon id
    * @throw  
    **/
    int getID();

    /** 
    * @pre 
    * @post return the Pokemon name using in Japan
    * @throw  
    **/
    string getJAP();

    private:
    string m_usa;
    string m_jap;
    int m_id;
};

#endif 
