#ifndef GAME_H
#define GAME_H
#include <string>
using namespace std;

class Game
{
    public:
    Game();
    string getName() const;
    int getYear() const;
    double getGibbRating() const;
    double getPubRating() const;
    double getWeight() const;
    int getMaxplayers() const;
    int getMaxTime() const;
    void setName(string Name);
    void setYear(int Year);
    void setGibbRating(double GR);
    void setPubRating(double PR);
    void setWeight(double WT);
    void setMaxplayers(int MP);
    void setMaxTime(int MT);
       

    private:
    string m_Name;
    int m_Year;
    double m_GibbRating;
    double m_PubRating;
    double m_Weight;
    int m_Maxplayers;
    int m_MaxTime;   
};

#endif
