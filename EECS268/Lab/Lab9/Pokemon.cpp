/**
 * @file Pokemon.cpp
 * @author Siliang Zhang
 * @brief This file will handle and store the Pokemon info
 * @date 2021-05-01
 */
#include "Pokemon.h"
#include "BNode.h"
#include <string>
using namespace std;

Pokemon::Pokemon()
{
    m_usa = "";
    m_id = 0;
    m_jap = "";
}

Pokemon::~Pokemon()
{
    
}

void Pokemon::setUSA(string name)
{
    m_usa = name;
}

void Pokemon::setID(int id)
{
    m_id = id;
}

void Pokemon::setJAP(string name)
{
    m_jap = name;
}

bool Pokemon::operator==(int id)
{
    return(m_id == id);
}

bool Pokemon::operator>(int id)
{
    return(m_id > id);
}

bool Pokemon::operator<(int id)
{
    return(m_id < id);
}

bool Pokemon::operator!=(int id)
{
    return (m_id != id);
}

bool Pokemon::operator==(Pokemon Poke)
{
    return(m_id == Poke.getID());
}

bool Pokemon::operator>(Pokemon Poke)
{
    return(m_id > Poke.getID());
}

bool Pokemon::operator<(Pokemon Poke)
{
    return(m_id < Poke.getID());
}

string Pokemon::getUSA()
{
    return m_usa;
}

int Pokemon::getID()
{
    return m_id;
}

string Pokemon::getJAP()
{
    return m_jap;
}