/* -----------------------------------------------------------------------------
 *
 * File Name: main.cpp
 * Author: Siliang Zhang
 * Assignment: EECS-168 Lab 4
 * Description: This program will allow the user to see the ASCII representation of a specific number they want or to see all the ASCII conversions from 33 to 126.
 * Date: 09/25/2020
 *
   ---------------------------------------------------------------------------- */
// Start your program.

#include <iostream>
using namespace std;

int main()
{
    int a;

    do
    {
        cout << "1) Select a specific number\n";
        cout << "2) Display visible ASCII values (33 to 126)\n";
        cout << "3) Exit\n";
        cout << "Choice: ";
        cin >> a;
        cout << " \n";

        if (cin.fail())
        {
            cin.clear();
            char a;
            cin >> a;
            cout << "Error------You have given an invalid choice.\n";
            cout << " \n";
        }

        else if (a != 1 && a != 2 && a != 3)
        {
            cout << "Error------You have given an invalid choice.\n";
            cout << " \n";
        }

        else if (a == 1)
        {
            int b;
            cout << "Enter value: ";
            cin >> b;
            cout << "" << b << " = " << char(b) << "\n\n";
        }

        else if (a == 2)
        {
            for (int i = 33; i <= 126; i++)
            {
                cout << "" << i << " = " << char(i) << "\n";
            }
            cout << " \n";
        }
    } while (a != 3);
}
