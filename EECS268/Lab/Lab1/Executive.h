#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include <string>
#include "Game.h"
using namespace std;

class Executive
{
    public:
    Executive(string lineCommand);
    ~Executive();
    void menuPrint() const;
    void run();
    void fileReadIn();
    void GamePrint(int i) const;
    void AllGames() const;
    void BlastFromPast() const;
    void RangePrint() const;
    void P_vs_G() const;
    void GameRecommend() const;

    private:
    Game **Games;
    string m_fileName;
    string* tempName;
    int* tempYear;
    double* tempGibbRating;
    double* tempPubRating;
    double* tempWeight;
    int* tempMaxplayers;
    int* tempMaxTime;
    int m_Size;
};

#endif