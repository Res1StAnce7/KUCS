/* -----------------------------------------------------------------------------
 *
 * File Name:  main.cpp
 * Author: Siliang Zhang 
 * Assignment: EECS-168 Lab 6
 * Description: This program will reads in the first value of the txt that receive the size of the array. Then, create an array to store all of those values and print the array.
 * Date: 10/18/2020
 *
 ---------------------------------------------------------------------------- */
//Start your program.

//Include the fstream library
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
  ifstream inFile; //create a variable of type ifstream. It will enable reading from files.
  inFile.open("input.txt"); //open a file that has values in it

  //Check if file is open
  if(inFile.is_open())
  {
  int b,c;
  char q;
  int* num = nullptr;
  int a = 0;
  inFile >> a;
  num = new int[a];

  for (int i = 0;i < a+1;i++)
  {
   if ( i != 0)
   {
    inFile >> num[i]; 
    }
   }
  
   cout << "Contents of input.txt: " << '\n';
   cout << "[";
   for (int i = 0;i < a+1;i++)
   {
    if ( i != 0)
    {
     cout << num[i];
     }

    if (i != 0 && i != a)
    {
     cout << ", ";
     }
    } 
   cout << "]" << '\n' << '\n';

  do
  {
   cout << "Input a value to search for: ";
   cin >> c;

   for (int i = 0;i < a+1;i++)
   { 
    if (num[i] == c && num[0] != c)
    {
     b = 1;
     cout << ""<< c <<" is in the array." << '\n';
     break;
     }
    
    else 
    {
     b = 0;
     }
    } 
   
   if (b == 0)
   {
    cout << ""<< c <<" is not in the array." << '\n';
   }

   cout << "Do you wish to quit ? (y/n): ";
   cin >> q;


  }while (q != 'y');

  num = NULL; //solve the error of "double free or corruption (out)"
  delete[] num;
   
  inFile.close(); //we're done using the file. 
   
   }

  else
  {
   cout << "File could not be opened!\n";
   }
  }