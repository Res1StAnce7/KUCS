/* -----------------------------------------------------------------------------
 *
 * File Name: main.cpp
 * Author: Siliang Zhang
 * Assignment: EECS-168 Lab 4
 * Description: This program will ask the user how many Fibonacci numbers they want to see.
 * Date: 09/25/2020
 *
 ---------------------------------------------------------------------------- */
// Start your program.

#include <iostream>
using namespace std;

int main()
{
    int a, F = 0, F1 = 0, F2 = 1;

    cout << "How many Fibonacci numbers do you want printed?: ";
    cin >> a;

    for (int i = 1; i <= a; i++)
    {
        if (i == 1)
        {
            cout << F1 << '\n';
        }
        else if (i == 2)
        {
            cout << F2 << '\n';
        }
        else if (i > 2)
        {
            F = F1 + F2;
            F1 = F2;
            F2 = F;
            cout << F << '\n';
        }
    }
}
