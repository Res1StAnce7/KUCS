/* -----------------------------------------------------------------------------
 *
 * File Name:  main.cpp
 * Author: Siliang Zhang
 * Assignment:   EECS-168 Lab 3
 * Description:  This program will obtain a wind speed from the user and tell them either what category or type if it's just a tropical storm.
 * Date: 09/18/2020
 *
 ---------------------------------------------------------------------------- */
// Start your program.

#include <iostream>
using namespace std;

int main()
{
    double a;

    cout << "Input a wind speed (m/s): ";
    cin >> a;

    if (a < 0){
        cout << "Negative wind? Sorry, that's invalid.\n";
    }
    else if (a < 18){
        cout << "A wind speed of " << a << " m/s is a Tropical Depression.\n";
    }
    else if (a < 33){
        cout << "A wind speed of " << a << " m/s is a Tropical Storm.\n";
    }
    else if (a < 43){
        cout << "A wind speed of " << a << " m/s is a Category 1 hurricane.\n";
    }
    else if (a < 50){
        cout << "A wind speed of " << a << " m/s is a Category 2 hurricane.\n";
    }
    else if (a < 58){
        cout << "A wind speed of " << a << " m/s is a Category 3 hurricane.\n";
    }
    else if (a < 70){
        cout << "A wind speed of " << a << " m/s is a Category 4 hurricane.\n";
    }
    else if (a >= 70){
        cout << "A wind speed of " << a << " m/s is a Category 5 hurricane.\n";
    }

    return 0;
}
