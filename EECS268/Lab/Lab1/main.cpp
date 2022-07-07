#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include "Executive.h"
#include "Game.h"
using namespace std;

int main(int argc, char** argv)
{
  if(argc < 2)
  {
    cout << "Incorrect number of parameters!\n";
  }
  
  else
  {
    Executive exec(argv[1]); 
    exec.run();
  }  

  return(0);
}