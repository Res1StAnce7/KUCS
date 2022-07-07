/**
 * @file FileReader.cpp
 * @author Siliang Zhang
 * @brief This file will handle the maze file and deal with data related to the traverse process
 * @date 2021-04-01
 */
#include "FileReader.h"
#include <iostream>
#include <fstream>
using namespace std;

FileReader::FileReader(string fileName)
{
    m_fileName = fileName;
    maze = nullptr;
    mazeOPT = nullptr;
    visited = nullptr;
    nR = 0;
    nC = 0;
    sR = 0;
    sC = 0;
}

FileReader::~FileReader()
{
    if (maze != nullptr)
    {
        for (int i = 0; i < nR; i++)
        {
            delete[] maze[i];
        }
        delete[] maze;
    }

    if (mazeOPT != nullptr)
    {
        for (int i = 0; i < nR; i++)
        {
            delete[] mazeOPT[i];
        }
        delete[] mazeOPT;
    }

    if (visited != nullptr)
    {
        for (int i = 0; i < nR; i++)
        {
            delete[] visited[i];
        }
        delete[] visited;
    }
}

bool FileReader::read()
{
    fstream inFile;
    inFile.open(m_fileName);
    if (inFile.is_open())
    {
        inFile >> nR;
        inFile >> nC;
        inFile >> sR;
        inFile >> sC;

        if (nR < 1 || nC < 1 || sR < 0 || sC < 0 || nR <= sR || nC <= sC)
        {
            if (sR < 0 || sC < 0 || nR <= sR || nC <= sC)
            {
                cout << "Invalid Statring Point!" << endl;
            }

            else if (nR < 1 || nC < 1)
            {
                cout << "Invalid Maze!" << endl;
            }

            inFile.close();
            return false;
        }

        maze = new char *[nR];
        mazeOPT = new int *[nR];
        visited = new bool *[nR];
        for (int i = 0; i < nR; i++)
        {
            maze[i] = new char[nC];
            mazeOPT[i] = new int[nC];
            visited[i] = new bool[nC];
        }
        
        for (int i = 0; i < nR; i++)
        {
            for (int j = 0; j < nC; j++)
            {
                inFile >> maze[i][j];
                mazeOPT[i][j] = 0;
                visited[i][j] = false;
            }
        }

        if (maze[sC][sR] != 'W')
        {
            inFile.close();
            return true;
        }

        else if (maze[sR][sC] == 'W')
        {
            cout << "Invalid Statring Point!" << endl;
            inFile.close();
            return false;
        }
    }

    else
    {
        cout << "The file does not exist!" << endl;
        inFile.close();
        return false;
    }
}

char FileReader::getInfo(int row, int col)
{
    return maze[row][col];
}

int FileReader::traverseOPT(int row, int col)
{
    return mazeOPT[row][col];
}

void FileReader::setOPT(int row, int col, int value)
{
    mazeOPT[row][col] = value;
}

void FileReader::setVisited(int row, int col, bool value)
{
    visited[row][col] = value;
}

bool FileReader::getVisited(int row, int col)
{
    return visited[row][col];
}

int FileReader::getNR()
{
    return nR;
}

int FileReader::getNC()
{
    return nC;
}

int FileReader::getSR()
{
    return sR;
}

int FileReader::getSC()
{
    return sC;
}
