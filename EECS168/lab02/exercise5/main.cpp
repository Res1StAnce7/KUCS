/* -----------------------------------------------------------------------------
 *
 * File Name:  main.cpp
 * Author: Siliang Zhang 
 * Assignment:   EECS-168 Lab 2
 * Description:  This program will take a number of sodas and then tell the user how many Fridge Cubes, six packs, and single sodas it will be packages as.
 * Date: 09/13/2020
 *
 ---------------------------------------------------------------------------- */
//Start your program.

#include <iostream>
using namespace std;
int main()
{
    int a, b, c;

    cout << "How many sodas do you have? ";
    cin >> a;

    cout << "Fridge Cubes:" << a / 24 << endl;
    b = (a % 24) / 6;
    cout << "Six-packs:" << b << endl;
    c = (a % 24) % 6;
    cout << "Singles:" << c << endl;

    return (0);
}