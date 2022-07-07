/* -----------------------------------------------------------------------------
 *
 * File Name:  main.cpp
 * Author: Siliang Zhang
 * Assignment: EECS-168 Lab 5
 * Description: This program will present the user with a choice of patterns.
 * Date: 10/03/2020
 *
 ---------------------------------------------------------------------------- */
// Start your program.

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a, b, c, d, e, g, h, r, x, y;
    string p, q;

    do
    {
        cout << "1) Checkerboard\n";
        cout << "2) Rook Path\n";
        cout << "3) Running Total\n";
        cout << "4) Upper Left Triangle\n";
        cout << "5) Upper Right Triangle\n";
        cout << "Input a choice: ";
        cin >> a;

        do
        {
            if (cin.fail())
            {
                cin.clear();
                cin.ignore();
                cout << "Error------please input a valid choice: ";
                cin >> a;
            }

            else if (a != 1 && a != 2 && a != 3 && a != 4 && a != 5)
            {
                cout << "Error------please input a valid choice: ";
                cin >> a;
            }
        } while (cin.fail() || (a != 1 && a != 2 && a != 3 && a != 4 && a != 5));

        if (a == 1)
        {
            cout << "Input a size: ";
            cin >> b;

            do
            {
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore();
                    cout << "Error------please input a valid size: ";
                    cin >> b;
                }
                else if (b <= 3)
                {
                    cout << "Error------please input a valid size: ";
                    cin >> b;
                }
            } while (cin.fail() || b <= 3);

            for (int j = 1; j <= b; j++)
            {
                if (j % 2 != 0)
                {
                    for (int i = 1; i <= b; i++)
                    {
                        if (i % 2 != 0)
                        {
                            cout << "O";
                        }
                        else
                        {
                            cout << "X";
                        }
                    }
                    cout << " \n";
                }
                else
                {
                    for (int i = 1; i <= b; i++)
                    {
                        if (i % 2 != 0)
                        {
                            cout << "X";
                        }
                        else
                        {
                            cout << "O";
                        }
                    }
                    cout << " \n";
                }
            }
        }

        else if (a == 2)
        {
            cout << "Please pick the size for the pattern: ";
            cin >> c;
            do
            {
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore();
                    cout << "Error------please input a valid size: ";
                    cin >> c;
                }
                else if (c <= 3)
                {
                    cout << "Error------please input a valid size: ";
                    cin >> c;
                }
            } while (cin.fail() || c <= 3);

            cout << "Please pick the position of the Rook on the x-axis: ";
            cin >> x;

            do
            {
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore();
                    cout << "Error------please input a valid position: ";
                    cin >> x;
                }
                else if (x >= c)
                {
                    cout << "Error------please input a valid position: ";
                    cin >> x;
                }
                else if (x < 0)
                {
                    cout << "Error------please input a valid position: ";
                    cin >> x;
                }

            } while (cin.fail() || x >= c || x < 0);

            cout << "Please pick the position of the Rook on the y-axis: ";
            cin >> y;

            do
            {
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore();
                    cout << "Error------please input a valid position: ";
                    cin >> y;
                }
                else if (y >= c)
                {
                    cout << "Error------please input a valid position: ";
                    cin >> y;
                }
                else if (y < 0)
                {
                    cout << "Error------please input a valid position: ";
                    cin >> y;
                }

            } while (cin.fail() || y >= c || y < 0);

            cout << "The postion of the Rook is (" << x << "," << y << ")\n";

            for (int k = 1; k <= c; k++)
            {
                if (k == x + 1)
                {
                    for (int l = 1; l <= c; l++)
                    {
                        if (l != y + 1)
                        {
                            cout << "-";
                        }
                        else
                        {
                            cout << "R";
                        }
                    }
                    cout << " \n";
                }
                else
                {
                    for (int m = 1; m <= c; m++)
                    {
                        if (m != y + 1)
                        {
                            cout << "*";
                        }
                        else
                        {
                            cout << "|";
                        }
                    }
                    cout << " \n";
                }
            }
        }

        else if (a == 3)
        {
            cout << "Please pick the size for the NxN matrix of numbers: ";
            cin >> d;
            do
            {
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore();
                    cout << "Error------please input a valid size: ";
                    cin >> d;
                }
                else if (d <= 3)
                {
                    cout << "Error------please input a valid size: ";
                    cin >> d;
                }
            } while (cin.fail() || d <= 3);

            int z = 1;

            for (int n = 1; n <= d * d; n++)
            {
                cout << z;
                if (z % d != 0)
                {
                    cout << ",";
                }
                else if (z % d == 0)
                {
                    cout << " \n";
                }
                z = z + 1;
            }
        }

        else if (a == 4)
        {
            cout << "Please pick the size for Upper Left Triangle: ";
            cin >> e;
            do
            {
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore();
                    cout << "Error------please input a valid size: ";
                    cin >> e;
                }
                else if (e <= 3)
                {
                    cout << "Error------please input a valid size: ";
                    cin >> e;
                }
            } while (cin.fail() || e <= 3);

            g = e;

            for (int o = 1; o <= e; o++)
            {
                for (int f = g; f >= 1; f--)
                {
                    cout << "*";
                }
                cout << " \n";
                g--;
            }
        }

        else if (a == 5)
        {
            cout << "Please pick the size for Upper Right Triangle: ";
            cin >> h;
            do
            {
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore();
                    cout << "Error------please input a valid size: ";
                    cin >> h;
                }
                else if (h <= 3)
                {

                    cout << "Error------please input a valid size: ";
                    cin >> h;
                }
            } while (cin.fail() || h <= 3);

            r = 1;

            for (int p = 1; p <= h; p++)
            {
                for (int s = 1; s <= r; s++)
                {
                    cout << "*";
                }
                cout << " \n";
                r++;
            }
        }

        cout << "Do you want to quit (y/n)?: ";
        cin >> q;
        if (q != "y" && q != "n")
        {
            do
            {
                cout << "Error------please input a valid choice: ";
                cin >> q;
                p = q;
                getline(cin, q);

            } while (p != "y" && p != "n");
        }

    } while (q != "y");
    cout << "Goodbye...\n";
}
