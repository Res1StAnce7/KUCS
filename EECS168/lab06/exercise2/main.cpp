/* -----------------------------------------------------------------------------
 *
 * File Name:  main.cpp
 * Author: Siliang Zhang 
 * Assignment: EECS-168 Lab 6
 * Description: This program will let the user decide how big this array is, prompt the user to populate the array with strings and display the longest and shortest string.
 * Date: 10/17/2020
 *
 ---------------------------------------------------------------------------- */
//Start your program.

#include <iostream>
#include <string>
using namespace std;

int main()
{
string* words = nullptr;
int numWords = 0;

cout << "Input an array size for you words array: ";
cin >> numWords;

do
{
 if (cin.fail())
 {
  cin.clear();
  cin.ignore();
  cout << "The size must be at least 1." << '\n';
  cout << "Please input the size again: ";
  cin >> numWords;
   }
 else if (numWords < 1)
 {
  cout << "The size must be at least 1." << '\n';
  cout << "Please input the size again: ";
  cin >> numWords;
   }
  }while(cin.fail() || numWords < 1); 
 

cout << "Now please enter "<< numWords <<" words" << '\n';

words = new string[numWords];
for (int i = 0;i < numWords;i++)
{
 cout << "Input a word: ";
 cin >> words[i]; 
  }

string lg,st;

int* N = nullptr;
int n = numWords;
N = new int[n];

for (int i = 0;i < numWords;i++)
{
 N[i] = words[i].length();
  }

int max = N[0];
int min = N[0];

for (int i = 0;i < numWords;i++)
{
 
 if (N[i] > max && N[i] > min )
 {
  max = N[i];
  lg = words[i];
   }

else if (N[i] == max && N[i] == min )
 {
  max = N[i];
  lg = words[i];
  min = N[i];
  st = words[i];
   }

 else if (N[i] < max && N[i] < min)
 {
  min = N[i];
  st = words[i];  
   }
 }
cout << "The longest word is: "<< lg <<"" << '\n';
cout << "The shortest word is: "<< st <<"" << '\n'; 

delete[] words;
delete[] N;

 }
