/* -----------------------------------------------------------------------------
 *
 * File Name:  main.cpp
 * Author: Siliang Zhang 
 * Assignment: EECS-168 Lab 6
 * Description: This program will perform the function of Arrays, reading from File and writing to File.
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
 double b;
 double* num = nullptr;
 int a = 0;
 inFile >> a;
 num = new double[a];

 for (int i = 0;i < a+1;i++)
 {
  if ( i != 0)
  {
   inFile >> num[i];
   }
  }
  
 ofstream myOutFile1;
 string fileName1 = "normalized.txt";
 myOutFile1.open(fileName1); 

 myOutFile1 << "Original array: ["; 
  
 for (int i = 0;i < a+1;i++)
 {
  if (i != 0)
  {
   myOutFile1 << num[i];
   }
    
  if (i != 0 && i != a)
  {
   myOutFile1 << ", ";
   }
  }

 myOutFile1 << "]" << '\n' ;

 int max = num[1];
 int min = num[1];

 for (int i = 0;i < a+1;i++)
 {
  if (num[i] > max && num[i] > min && i != 0 )
 {
  max = num[i];
  }

 else if (num[i] == max && num[i] == min && i != 0)
 {
  max = num[i];
  min = num[i];
  }

 else if (num[i] < max && num[i] < min && i != 0 )
 {
  min = num[i];
  }
 }

 myOutFile1 << "Normalized array: [";

 for (int i = 0;i < a+1;i++)
 {
  if (num[i] == max && i != 0) 
  {
   myOutFile1 << "1";  
   }

  else if (num[i] == min && i != 0)
  {
   myOutFile1 << "0"; 
   }

  else if ((num[i] != max && num[i] != min) && i != 0)
  {
   b = (num[i] - min) / (max - min);
   myOutFile1 << b ;
   }

  if (i != 0 && i != a)
  {
    myOutFile1 << ", ";
    }
  }

  myOutFile1 << "]";

 ofstream myOutFile2;
 string fileName2 = "reserved.txt";
 myOutFile2.open(fileName2); 

 myOutFile2 << "Original array: ["; 
  
 for (int i = 0;i < a+1;i++)
 {
  if (i != 0)
  {
   myOutFile2 << num[i];
   }
    
  if (i != 0 && i != a)
  {
   myOutFile2 << ", ";
   }
  }

 myOutFile2 << "]" << '\n';

 myOutFile2 << "Reversed array: [";

 for (int i = a;i > 0;i--)
 {
  myOutFile2 << num[i];

  if (i != 1)
  {
   myOutFile2 << ", "; 
   }
  }

 myOutFile2 << "]" << '\n';
  
 num = NULL; //solve the error of "double free or corruption (out)"
 delete[] num;
   
 inFile.close(); //we're done using the file. 
   
  }

 else
 {
  cout << "File could not be opened!\n";
  }

 }

