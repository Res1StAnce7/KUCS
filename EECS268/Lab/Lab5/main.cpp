/**
 * @file main.cpp
 * @author Siliang Zhang
 * @brief This file will take in the lincommand, create Executive, then run the show
 * @date 2021-03-22
 */
#include <iostream>
#include "Executive.h"
using namespace std;

int main(int argc, char **argv)
{
  if (argc < 2)
  {
    cout << "Incorrect number of parameters!\n";
  }

  else
  {
    Executive exec(argv[1]);
    exec.run();
  }

  return (0);
}