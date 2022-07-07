/* -----------------------------------------------------------------------------
 *
 * File Name: main.cpp
 * Author: Siliang Zhang
 * Assignment: EECS-168 Lab 4
 * Description: This program will ask the user for what day they want a count of people with the flu for. Then display the amount.
 * Date: 09/26/2020
 *
 ---------------------------------------------------------------------------- */
// Start your program.

#include <iostream>
using namespace std;

int main()
{
    long long a, F = 0, F1 = 1, F2 = 5, F3 = 17;

    cout << "OUTBREAK!\n";
    cout << "What day do you want a sick count for?: ";
    cin >> a;

    if (a == 0)
    {
        cout << "Invalid day\n";
    }
    else if (a == 1)
    {
        cout << "Total people with flu: " << F1 << "\n";
    }
    else if (a == 2)
    {
        cout << "Total people with flu: " << F2 << "\n";
    }
    else if (a == 3)
    {
        cout << "Total people with flu: " << F3 << "\n";
    }
    else if (a > 3)
    {
        for (int i = 3; i <= a; i++)
        {
            F = F1 + F2 + F3;
            F1 = F2;
            F2 = F3;
            F3 = F;
        }
        cout << "Total people with flu: " << F << "\n";
    }
}
