#include "Game.h"
using namespace std;

Game::Game()
{
    m_Name = "";
    m_Year = 0;
    m_GibbRating = 0;
    m_PubRating = 0;
    m_Weight = 0;
    m_Maxplayers = 0;
    m_MaxTime = 0;
}

string Game::getName() const
{
    return (m_Name);
}

int Game::getYear() const
{
    return (m_Year);
}

double Game::getGibbRating() const
{
    return (m_GibbRating);
}

double Game::getPubRating() const
{
    return (m_PubRating);
}

double Game::getWeight() const
{
    return (m_Weight);
}

int Game::getMaxplayers() const
{
    return (m_Maxplayers);
}

int Game::getMaxTime() const
{
    return (m_MaxTime);
}

void Game::setName(string Name)
{
    m_Name = Name;
}

void Game::setYear(int Year)
{
    m_Year = Year;
}

void Game::setGibbRating(double GR)
{
    m_GibbRating = GR;
}

void Game::setPubRating(double PR)
{
    m_PubRating = PR;
}

void Game::setWeight(double MT)
{
    m_Weight = MT;
}

void Game::setMaxplayers(int MP)
{
    m_Maxplayers = MP;
}

void Game::setMaxTime(int MT)
{
    m_MaxTime = MT;
}
