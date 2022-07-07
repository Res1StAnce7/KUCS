/**
 * @file Executive.cpp
 * @author Siliang Zhang
 * @brief This file will create a Browser and run the show
 * @date 2021-03-22
 */
#include <iostream>
#include <string>
#include <fstream>
#include "Executive.h"
#include "BrowserHistory.h"
#include "LinkedList.h"
using namespace std;

Executive::Executive(string lineCommand)
{
    m_filename = lineCommand;
}

void Executive::run()
{
    fstream inFile;
    inFile.open(m_filename);

    if (inFile.is_open())
    {
        string command;
        string URL;
        BrowserHistory *Browser = new BrowserHistory();

        inFile >> command;
        do
        {
            bool check = 0;
            if (command.compare("NAVIGATE") == 0)
            {
                inFile >> URL;
                Browser->navigateTo(URL);
            }

            else if (command.compare("BACK") == 0)
            {
                Browser->back();
            }

            else if (command.compare("FORWARD") == 0)
            {
                Browser->forward();
            }

            else if (command.compare("HISTORY") == 0)
            {
                Browser->history();

                check = 1;
                inFile >> command;
                if (!inFile.eof())
                {
                    cout << endl;
                }
            }

            if (check == 0)
            {
                inFile >> command;
            }
        } while (!inFile.eof());

        delete Browser;

        inFile.close();
    }

    else
    {
        cout << "THe file cannot be opened!" << endl;
    }
}