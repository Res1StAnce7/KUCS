#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include "Executive.h"
#include "Game.h"
using namespace std;

Executive::Executive(string lineCommand)
{
    m_fileName = lineCommand;
    m_Size = 0;
    Games = nullptr;
    tempName = nullptr;
    tempYear = nullptr;
    tempGibbRating = nullptr;
    tempPubRating = nullptr;
    tempWeight = nullptr;
    tempMaxplayers = nullptr;
    tempMaxTime = nullptr;
}

Executive::~Executive()
{
    if (tempName != nullptr)
    {
        delete[] tempName;
    }

    if (tempYear != nullptr)
    {
        delete[] tempYear;
    }

    if (tempGibbRating != nullptr)
    {
        delete[] tempGibbRating;
    }

    if (tempPubRating != nullptr)
    {
        delete[] tempPubRating;
    }

    if (tempWeight != nullptr)
    {
        delete[] tempWeight;
    }

    if (tempMaxplayers != nullptr)
    {
        delete[] tempMaxplayers;
    }

    if (tempMaxTime != nullptr)
    {
        delete[] tempMaxTime;
    }

    if (Games != nullptr)
    {
        for (int i = 0; i < m_Size; i++)
        {
            delete Games[i];
        }

        delete[] Games;
    }
}

void Executive::menuPrint() const
{
    cout << "User's Menu:" << endl;
    cout << "1.Print all games" << endl;
    cout << "2.Blast from the past" << endl;
    cout << "3.Print a ranking range" << endl;
    cout << "4.The People VS Dr. Gibbons" << endl;
    cout << "5.Find game recommendations" << endl;
    cout << "6.Exit the program" << endl;
    cout << "Input your choice: ";
}

void Executive::fileReadIn()
{
    fstream inFile;
    inFile.open(m_fileName);

    if (inFile.is_open())
    {
        int size = 0;

        inFile >> size;
        m_Size = size;

        Games = new Game*[m_Size];
        tempName = new string[m_Size];
        tempYear = new int[m_Size];
        tempGibbRating = new double[m_Size];
        tempPubRating = new double[m_Size];
        tempWeight = new double[m_Size];
        tempMaxplayers = new int[m_Size];
        tempMaxTime = new int[m_Size];

        for (int i = 0; i < m_Size; i++)
        {
            Games[i] = new Game();
        }

        for (int i = 0; i < m_Size; i++)
        {
            inFile >> tempName[i];
            inFile >> tempYear[i];
            inFile >> tempGibbRating[i];
            inFile >> tempPubRating[i];
            inFile >> tempWeight[i];
            inFile >> tempMaxplayers[i];
            inFile >> tempMaxTime[i];
        }

        for (int i = 0; i < m_Size; i++)
        {
            Games[i]->setName(tempName[i]);
            Games[i]->setYear(tempYear[i]);
            Games[i]->setGibbRating(tempGibbRating[i]);
            Games[i]->setPubRating(tempPubRating[i]);
            Games[i]->setWeight(tempWeight[i]);
            Games[i]->setMaxplayers(tempMaxplayers[i]);
            Games[i]->setMaxTime(tempMaxTime[i]);
        }

        inFile.close();
    }

    else
    {
        cout << "Error! The file cannot be opened!" << endl;
        exit(0);
    }
}

void Executive::GamePrint(int i) const
{
    cout << "" << Games[i]->getName() << " (" << Games[i]->getYear() << ") ";
    cout << "[GR=" << Games[i]->getGibbRating() << ", PR=" << Games[i]->getPubRating() << ", WT=" << Games[i]->getWeight() << ", MP=" << Games[i]->getMaxplayers() << ", MT=" << Games[i]->getMaxTime() << "]" << endl;
}

void Executive::AllGames() const
{
    for (int i = 0; i < m_Size; i++)
    {
        GamePrint(i);
    }
}

void Executive::BlastFromPast() const
{
    int tempYearC2 = 10000;

    for (int i = 0; i < m_Size; i++)
    {
        if (tempYearC2 >= Games[i]->getYear())
        {
            tempYearC2 = Games[i]->getYear();
        }
    }

    for (int i = 0; i < m_Size; i++)
    {
        if (tempYearC2 == Games[i]->getYear())
        {
            GamePrint(i);
        }
    }
}

void Executive::RangePrint() const
{
    double RangeLeft, RangeRight;

    cout << "Input the first number of the ranking range (e.g. 1-10): ";
    cin >> RangeLeft;
    do
    {
        if (cin.fail() || RangeLeft < 0)
        {
            cin.clear();
            cin.ignore();
            cout << "The first ranking should be between 0 and 10. Please try again: ";
            cin >> RangeLeft;
        }
    } while (cin.fail() || RangeLeft < 0);

    cout << "Input the second number of the ranking range (e.g. 1-10): ";
    cin >> RangeRight;
    do
    {
        if (cin.fail() || RangeRight < 0 || RangeRight > 10 || RangeRight < RangeLeft)
        {
            cin.clear();
            cin.ignore();
            cout << "The second ranking should be greater that the first one and also between 0 and 10. Please try again: ";
            cin >> RangeRight;
        }
    } while (cin.fail() || RangeRight < 0 || RangeRight < RangeLeft);

    int checkC3 = 0;

    for (int i = 0; i < m_Size; i++)
    {
        if (RangeLeft <= Games[i]->getGibbRating() && Games[i]->getGibbRating() <= RangeRight)
        {
            checkC3 = 1;
            GamePrint(i);
        }
    }

    if (checkC3 == 0)
    {
        cout << "No match game found!" << endl;
    }
}

void Executive::P_vs_G() const
{
    double Rating;

    cout << "Input a number: ";
    cin >> Rating;

    do
    {
        if (cin.fail() || Rating < 0 || Rating > 10)
        {
            cin.clear();
            cin.ignore();
            cout << "The maximum difference is 10. Please try again: ";
            cin >> Rating;
        }
    } while (cin.fail() || Rating < 0 || Rating > 10);

    int checkC4 = 0;

    for (int i = 0; i < m_Size; i++)
    {
        if (fabs(Games[i]->getGibbRating() - Games[i]->getPubRating()) > Rating)
        {
            checkC4 = 1;
            GamePrint(i);
        }
    }
    if (checkC4 != 1)
    {
        cout << "No match game found!" << endl;
    }
}

void Executive::GameRecommend() const
{
    double DPT, PC, MR;

    cout << "Input your desired play time (in minutes): ";
    cin >> DPT;
    do
    {
        if (cin.fail() || DPT <= 0)
        {
            cin.clear();
            cin.ignore();
            cout << "Your input should be a number greater than zero. Please try again: ";
            cin >> DPT;
        }
    } while (cin.fail() || DPT <= 0);

    cout << "Input your max player count: ";
    cin >> PC;
    do
    {
        if (cin.fail() || PC <= 0)
        {
            cin.clear();
            cin.ignore();
            cout << "Your input should be a number greater than zero. Please try again: ";
            cin >> PC;
        }
    } while (cin.fail() || PC <= 0);

    cout << "Input the minimum ranking: ";
    cin >> MR;
    do
    {
        if (cin.fail() || MR <= 0)
        {
            cin.clear();
            cin.ignore();
            cout << "Your input should be a number which is not less than zero. Please try again: ";
            cin >> MR;
        }
    } while (cin.fail() || MR <= 0);

    int checkC5 = 0;

    for (int i = 0; i < m_Size; i++)
    {
        if (DPT >= Games[i]->getMaxTime() && MR <= Games[i]->getGibbRating() && PC <= Games[i]->getMaxplayers())
        {
            checkC5 = 1;
            GamePrint(i);
        }
    }

    if (checkC5 == 0)
    {
        cout << "Mo match game found!" << endl;
    }
}

void Executive::run()
{
    fileReadIn();

    int choice = 0;
    do
    {
        menuPrint();
        cin >> choice;
        do
        {
            if (choice < 1 || choice > 6 || cin.fail())
            {
                cin.clear();
                cin.ignore();
                cout << "Your input should be an int within 1-6. Please try again: ";
                cin >> choice;
            }
        } while (choice < 1 || choice > 6 || cin.fail());

        if (choice == 1)
        {
            AllGames();
        }

        else if (choice == 2)
        {
            BlastFromPast();
        }

        else if (choice == 3)
        {
            RangePrint();
        }

        else if (choice == 4)
        {
            P_vs_G();
        }

        else if (choice == 5)
        {
            GameRecommend();
        }

        else if (choice == 6)
        {
            cout << "Success!" << endl;
        }
    } while (choice != 6);
}