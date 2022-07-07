/* -----------------------------------------------------------------------------
 *
 * File Name:  main.cpp
 * Author: Siliang Zhang
 * Assignment: EECS-168 Lab 8
 * Description: This program will uses several function definitions and prsent a menu.
 * Date: 10/30/2020
 *
 ---------------------------------------------------------------------------- */
// Start your program.
#include <iostream>
#include <string>
using namespace std;

int lastDigit(int n)
{
    n = n % 10;
    return (n);
}

int removeLastDigit(int n)
{
    int c = n;
    string str = to_string(n);
    int b = str.length();

    if (b == 1)
    {
        return (0);
    }

    else
    {
        c = c % 10;
        n = (n - c) / 10;
        return (n);
    }
}

int addDigit(int currentNum, int newDigit)
{
    return (currentNum * 10 + newDigit);
}

int reverse(int n)
{
    int reverse = 0;
    do
    {
        reverse = addDigit(reverse, lastDigit(n));
        n = removeLastDigit(n);
    } while (n != 0);
    return reverse;
}

bool isPalindrome(int n)
{
    return (n == reverse(n));
}

int countDigits(int n)
{
    int count = 0;
    do
    {
        n = removeLastDigit(n);
        count++;
    } while (n != 0);
    return count;
}

int sumDigits(int n)
{
    int sum = 0;
    do
    {
        sum = sum + lastDigit(n);
        n = removeLastDigit(n);
    } while (n != 0);
    return sum;
}

void printMenu()
{
    cout << "1) Count digits" << '\n';
    cout << "2) Sum digits" << '\n';
    cout << "3) Is Palindrome" << '\n';
    cout << "4) Reverse " << '\n';
    cout << "5) Exit" << '\n';
}

void run()
{
    int num;
    int choice;
    do
    {
        printMenu();
        cout << "Please input your choice: ";
        cin >> choice;

        if (choice != 5)
        {
            cout << "Please input an integer: ";
            cin >> num;
        }

        if (choice == 1)
        {
            cout << "Count digits: " << countDigits(num) << '\n';
        }
        else if (choice == 2)
        {
            cout << "Sum digits: " << sumDigits(num) << '\n';
        }
        else if (choice == 3)
        {
            if (isPalindrome(num))
            {
                cout << "" << num << " is a palindrome number." << '\n';
            }
            else
            {
                cout << "" << num << " is not a palindrome number." << '\n';
            }
        }
        else if (choice == 4)
        {
            cout << "Reverse: " << reverse(num) << '\n';
        }
    } while (choice != 5);
}

int main()
{
    run();
    return (0);
}
