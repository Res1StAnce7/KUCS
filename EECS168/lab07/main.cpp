/* -----------------------------------------------------------------------------
 *
 * File Name:  main.cpp
 * Author: Siliang Zhang
 * Assignment: EECS-168 Lab 7
 * Description: This program will perform the function of 2D-Arrays.
 * Date: 10/23/2020
 *
 ---------------------------------------------------------------------------- */
// Start your program.

// Include the fstream library
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    ifstream inFile; // create a variable of type ifstream. It will enable reading from files.
    string fileName0;
    cout << "Please input the name of the file: ";
    cin >> fileName0;
    inFile.open(fileName0); // open a file that has values in it

    // Check if file is open
    if (inFile.is_open())
    {
        double **num = nullptr;

        int row = 0;
        inFile >> row;

        num = new double *[row];

        int col = 0;
        inFile >> col;

        double sum;

        for (int i = 0; i < row; i++)
        {
            num[i] = new double[col];
        }

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                inFile >> num[i][j];
            }
        }

        ofstream myOutFile1;
        string fileName1 = "averages.txt";
        myOutFile1.open(fileName1);

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                sum += num[i][j];
            }
        }
        myOutFile1 << "Total average: " << sum / (row * col) << "" << '\n';

        for (int i = 0; i < row; i++)
        {
            double sum0 = 0;
            for (int j = 0; j < col; j++)
            {
                sum0 += num[i][j];
            }
            myOutFile1 << "Row " << i + 1 << " average: " << sum0 / col << "" << '\n';
        }

        ofstream myOutFile2;
        string fileName2 = "reserve.txt";
        myOutFile2.open(fileName2);

        for (int i = 0; i < row; i++)
        {
            for (int j = col - 1; j >= 0; j--)
            {
                myOutFile2 << fixed << setprecision(1) << num[i][j];

                if (j != 0)
                {
                    myOutFile2 << " ";
                }
            }
            myOutFile2 << '\n';
        }

        ofstream myOutFile3;
        string fileName3 = "flipped.txt";
        myOutFile3.open(fileName3);

        for (int i = row - 1; i >= 0; i--)
        {
            for (int j = 0; j < col; j++)
            {
                myOutFile3 << fixed << setprecision(1) << num[i][j];

                if (j != 4)
                {
                    myOutFile3 << " ";
                }
            }
            myOutFile3 << '\n';
        }

        if (row = col)
        {
            ofstream myOutFile4;
            string fileName4 = "diagonal.txt";
            myOutFile4.open(fileName4);

            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    myOutFile4 << fixed << setprecision(1) << num[j][i];

                    if (i != 4)
                    {
                        myOutFile4 << " ";
                    }
                }
                myOutFile4 << '\n';
            }
        }

        for (int i = 0; i < row; i++)
        {
            delete[] num[i];
        }
        delete[] num;

        inFile.close(); // we're done using the file.
    }
    else
    {
        cout << "File could not be opened!\n";
    }
}