/* -----------------------------------------------------------------------------
 *
 * File Name:  main.cpp
 * Author: Siliang Zhang
 * Assignment:   EECS-168 Lab 2
 * Description:  This program will use the Math class to perform square root calculations.
 * Date: 09/11/2020
 *
 ---------------------------------------------------------------------------- */
// Start your program.

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    double a, b;

    cout << "Will use the formula a^2 + b^2 = c^2 to solve for the hypotenuse of a triangle" << endl;
    cout << "Input a value for a: ";
    cin >> a;
    cout << "Input a value for b: ";
    cin >> b;
    cout << "The hypotenuse is: " << sqrt(a * a + b * b) << endl;

    return 0;
}