/* -----------------------------------------------------------------------------
 *
 * File Name:  main.cpp
 * Author: Siliang Zhang 
 * Assignment:   EECS-168 Lab 2
 * Description:  This program will solve the quadratic equation. 
 * Date: 09/11/2020
 *
 ---------------------------------------------------------------------------- */
//Start your program.

#include <iostream>
#include  <math.h>
using namespace std;

int main()
{
     double a, b, c;

     cout << "Input a: ";
     cin >> a;
     cout << "Input b: ";
     cin >> b;
     cout << "Input c: ";
     cin >> c;

     cout << "root 1: " << ((-b) + sqrt(b * b - 4 * a * c)) / (2 * a) << endl;
     cout << "root 2: " << ((-b) - sqrt(b * b - 4 * a * c)) / (2 * a) << endl;

     return (0);
}
