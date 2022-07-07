/* -----------------------------------------------------------------------------
 *
 * File Name:  main.cpp
 * Author: Siliang Zhang
 * Assignment:   EECS-168 Lab 3
 * Description:  This program will obtain a numerator and a denominator from the user. Then, display the result of long division from the user.
 * Date: 09/18/2020
 *
 ---------------------------------------------------------------------------- */
// Start your program.

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int a, b;

    cout << "Enter a numerator: ";
    cin >> a;
    cout << "Enter a denominator: ";
    cin >> b;

    if ((b == 0))
    {
        cout << "Sorry, you may not divide by zero.\n";
    }
    else
    {
        cout << "" << a << " / " << b << " = " << a / b << " Remainder " << a % b << "\n";
    }
}
