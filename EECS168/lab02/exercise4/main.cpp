/* -----------------------------------------------------------------------------
 *
 * File Name:  main.cpp
 * Author: Siliang Zhang
 * Assignment:   EECS-168 Lab 2
 * Description:  This program will convert cast a character to an int.
 * Date: 09/12/2020
 *
 ---------------------------------------------------------------------------- */
// Start your program.

#include <iostream>
using namespace std;

int main()
{
    char a;

    cout << "Input a character: ";
    cin >> a;

    cout << "The ASCII value is: " << (int)a << endl;
    cout << "Goodbye!" << endl;

    return (0);
}