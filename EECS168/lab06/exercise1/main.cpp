/* -----------------------------------------------------------------------------
 *
 * File Name:  main.cpp
 * Author: Siliang Zhang 
 * Assignment: EECS-168 Lab 6
 * Description: This program will present the basic numeric computation.
 * Date: 10/03/2020
 *
 ---------------------------------------------------------------------------- */
//Start your program.

#include <iostream>
using namespace std;

int main()
{
double* nums = nullptr;
double sum,avg,min,max;
int Size = 0;

cout << "Please enter 5 numbers" << '\n';

Size = 5;
nums = new double[Size];

for (int i = 1;i <= Size;i++)
{
 cout << "Input a number into your array: ";
 cin >> nums[i] ; 
  }

cout << "Here are all the numbers in your array:"<<'\n';
for (int i = 1;i <= Size;i++)
{

 cout << nums[i] <<'\n';   
  }

for (int i = 1;i <= Size;i++)
{
 sum += nums[i];   
  }

cout << "The sum of all the values is: "<< sum <<"" << '\n';

avg = sum / Size;
cout << "The average of all the values is: "<< avg <<"" << '\n';

max = nums[1];
min = nums[1];

for (int i = 1;i <= Size;i++)
{
 if (nums[i] > max && nums[i] > min)
 {
  max = nums[i];
 }
 else if (nums[i] == max && nums[i] == min )
 {
  max = nums[i];
  min = nums[i];
 }
 else if (nums[i] < max && nums[i] < min )
 {
  min = nums[i];
 }
}
 
cout << "The largest value is: "<< max <<"" << '\n';
cout << "The smallest value is: "<< min <<"" << '\n'; 

nums = NULL; //solve the error of "double free or corruption (out)"
delete[] nums;

 }
