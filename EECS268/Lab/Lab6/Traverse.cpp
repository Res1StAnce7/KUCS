/**
 * @file Traverse.cpp
 * @author Siliang Zhang
 * @brief This file will walk the maze
 * @date 2021-04-01 
 */
#include "Traverse.h"
#include "FileReader.h"
#include <iostream>
using namespace std;

Traverse::Traverse(string fileName)
{
    Reader = new FileReader(fileName);
    out = false;
    num = 0;
}

void Traverse::run()
{
    if (Reader->read())
    {
        mazeInfo();
        traverse(Reader->getSR(), Reader->getSC(), 2); //call traverse
        if(Out())
        {
            cout << "We escaped!" << endl;
        }

        else
        {
            cout << "No way out!" << endl;
        }
    }

    delete Reader;
}

void Traverse::traverse(int row, int col, int step)
{
    cout << "("<<row<<","<<col<<")" << endl;
    Reader->setVisited(row, col, true); //visited
    if (Reader->getInfo(row, col) == 'E')
    {
        print(); //print the way out after find the exit
        setOut(true);
    }

    else
    {
        for (int i = 0; i < 4; i++)
        {
            if (i == 0 && check(row - 1, col)) //up
            {
                if (!Reader->getVisited(row - 1, col)) //check if the next step is visited
                {
                    Reader->setOPT(row - 1, col, step); //set step
                    traverse(row - 1, col, step + 1); //next step
                    Reader->setVisited(row - 1, col, false); //not visited
                    Reader->setOPT(row - 1, col, 0); //set to default
                }
            }

            if (i == 1 && check(row, col + 1)) // right
            {
                if (!Reader->getVisited(row, col + 1)) //check if the next step is visited
                {
                    Reader->setOPT(row, col + 1, step); //set step
                    traverse(row, col + 1, step + 1); //next step
                    Reader->setVisited(row, col + 1, false); //not visited
                    Reader->setOPT(row, col + 1, 0); //set to default
                }
            }

            if (i == 2 && check(row + 1, col)) //down
            {
                if (!Reader->getVisited(row + 1, col)) //check if the next step is visited
                {
                    Reader->setOPT(row + 1, col, step); //set step
                    traverse(row + 1, col, step + 1); //next step
                    Reader->setVisited(row + 1, col, false); //not visited
                    Reader->setOPT(row + 1, col, 0); //set to default
                }
            }

            if (i == 3 && check(row, col - 1)) //left
            {
                if (!Reader->getVisited(row, col - 1)) //check if the next step is visited
                {
                    Reader->setOPT(row, col - 1, step); //set step
                    traverse(row, col - 1, step + 1); //next step
                    Reader->setVisited(row, col - 1, false); //not visited
                    Reader->setOPT(row, col - 1, 0); //set to default
                }
            }
        }
    }
}

bool Traverse::check(int row, int col)
{
    if (row > Reader->getNR() - 1 || col > Reader->getNC() - 1 || row < 0 || col < 0) // check if reach the boundary
    {
        return false;
    }

    else if (row <= Reader->getNR() - 1 && col <= Reader->getNC() - 1 && row >= 0 && col >= 0)
    {
        if (Reader->getInfo(row, col) == 'W') //check if reach the wall
        {
            return false;
        }
    }

    return true;
}

void Traverse::print()
{
    cout << "Solution #"<<++num<<":" << endl;
    Reader->setOPT(Reader->getSR(), Reader->getSC(), 1); 
    for (int i = 0; i < Reader->getNR(); i++)
    {
        for (int j = 0; j < Reader->getNC(); j++)
        {
            cout << Reader->traverseOPT(i, j) << '\t';
        }
        cout << endl;
    }
    
}

void Traverse::mazeInfo()
{
    cout << "Size: " << Reader->getNR() << "," << Reader->getNC() << "" << endl;
    cout << "Starting Point: " << Reader->getSR() << "," << Reader->getSC() << "" << endl;
}

void Traverse::setOut(bool escape)
{
    out = escape;
}

bool Traverse::Out()
{
    return out;
}

