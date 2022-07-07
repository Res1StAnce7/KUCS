/* -----------------------------------------------------------------------------
 *
 * File Name:  main.cpp
 * Author: Siliang Zhang
 * Assignment:   EECS-168 Lab 3
 * Description:  This program will ask the user if they want Tacos then Sushi then Deserts, ask them for their age which will affect the discount and Display a cost per item (before any discounts), a subtotal (before any discounts), a tax amount, a discount amount, and a grand total.
 * Date: 09/19/2020
 *
 ---------------------------------------------------------------------------- */
// Start your program.

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
    char a, b, c;
    int d, e, f, g;

    cout << "============================\n";
    cout << "WELCOME TO THE RESTAURANT\n";
    cout << "============================\n";
    cout << "Do you want Tacos? (y/n): ";
    cin >> a;

    if (a == 'y' || a == 'Y')
    {
        cout << "How many?: ";
        cin >> e;
        cout << " \n";
    }
    else
    {
        cout << " \n";
        e = 0;
    }

    cout << "Do you want Sushi? (y/n): ";
    cin >> b;

    if (b == 'y' || b == 'Y')
    {
        cout << "How many?: ";
        cin >> f;
        cout << " \n";
    }
    else
    {
        cout << " \n";
        f = 0;
    }

    cout << "Do you want Deserts? (y/n): ";
    cin >> c;
    if (c == 'y' || c == 'Y')
    {
        cout << "How many?: ";
        cin >> g;
        cout << " \n";
    }

    else
    {
        cout << " \n";
        g = 0;
    }

    cout << "How old are you?: ";
    cin >> d;
    cout << "============================\n";

    if (d >= 65)
    {
        cout << fixed;
        cout << "" << e << " Tacos @ $3.50 ==> $" << setprecision(3) << 3.50 * e << "\n";
        cout << "" << f << " Sushi @ $7.25 ==> $" << setprecision(3) << 7.25 * f << "\n";
        cout << "" << g << " Deserts @ $5.50 ==> $" << setprecision(3) << 5.50 * g << "\n";
        cout << "Subtotal: $" << setprecision(3) << 3.50 * e + 7.25 * f + 5.50 * g << "\n";
        cout << "Tax: $" << setprecision(3) << 0.50 * (3.50 * e + 7.25 * f + 5.50 * g) << "\n";
        cout << "Discount: $" << setprecision(3) << 0.10 * 1.50 * (3.50 * e + 7.25 * f + 5.50 * g) << "\n";
        cout << "============================\n";
        cout << "Total: $" << setprecision(3) << 0.9 * 1.50 * (3.50 * e + 7.25 * f + 5.50 * g) << "\n\n";
    }

    else if (d <= 12)
    {
        cout << fixed;
        cout << "" << e << " Tacos @ $3.50 ==> $" << setprecision(3) << 3.50 * e << "\n";
        cout << "" << f << " Sushi @ $7.25 ==> $" << setprecision(3) << 7.25 * f << "\n";
        cout << "" << g << " Deserts @ $5.50 ==> $" << setprecision(3) << 5.50 * g << "\n";
        cout << "Subtotal: $" << setprecision(3) << 3.50 * e + 7.25 * f + 5.50 * g << "\n";
        cout << "Tax: $" << setprecision(3) << 0.50 * (3.50 * e + 7.25 * f + 5.50 * g) << "\n";
        cout << "Discount: $" << setprecision(3) << 1.50 * 5.50 * g << "\n";
        cout << "============================\n";
        cout << "Total: $" << setprecision(3) << 1.50 * (3.50 * e + 7.25 * f) << "\n\n";
    }

    else if (d > 12 && d < 65)
    {
        cout << fixed;
        cout << "" << e << " Tacos @ $3.50 ==> $" << setprecision(3) << 3.50 * e << "\n";
        cout << "" << f << " Sushi @ $7.25 ==> $" << setprecision(3) << 7.25 * f << "\n";
        cout << "" << g << " Deserts @ $5.50 ==> $" << setprecision(3) << 5.50 * g << "\n";
        cout << "Subtotal: $" << setprecision(3) << 3.50 * e + 7.25 * f + 5.50 * g << "\n";
        cout << "Tax: $" << setprecision(3) << 0.50 * (3.50 * e + 7.25 * f + 5.50 * g) << "\n";
        cout << "Discount: $0.000\n";
        cout << "============================\n";
        cout << "Total: $" << setprecision(3) << 1.50 * (3.50 * e + 7.25 * f + 5.50 * g) << "\n\n";
    }

    cout << "Please come again!\n\n";
}
