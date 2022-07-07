/* -----------------------------------------------------------------------------
 *
 * File Name:  main.cpp
 * Author: Siliang Zhang
 * Assignment:   EECS-168 Lab 2
 * Description:  This program will convert  the temperature in Fahrenheit to the temperature Celsius..
 * Date: 09/12/2020
 *
 ---------------------------------------------------------------------------- */
// Start your program.

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    double a, b;

    cout << "Input a temperature in Fahrenheit: ";
    cin >> a;

    b = int((a - 32) * (5.0 / 9));

    cout << "The temperature in Celsius is: " << b << endl;

    return 0;
}
