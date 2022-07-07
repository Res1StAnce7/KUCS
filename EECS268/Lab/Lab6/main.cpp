/**
 * @file main.cpp
 * @author Siliang Zhang
 * @brief This file will creeate Traverse and walk the maze
 * @date 2021-04-01
 */
#include <iostream>
#include "Traverse.h"
using namespace std;

int main(int argc, char **argv)
{
  if (argc < 2)
  {
    cout << "Incorrect number of parameters!\n";
  }

  else
  {
    Traverse exec(argv[1]);
    exec.run();
  }

  return (0);
}