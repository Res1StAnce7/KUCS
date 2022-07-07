/**
 * @file main.cpp
 * @author Siliang Zhang
 * @brief This file will call Executive and run the show
 * @date 2021-05-01
 */
#include <iostream>
#include "Executive.h"
using namespace std;

int main(int argc, char** argv)
{
    system("color F0");
    if (argc < 2)
    {
        cout << "Incorrect number of parameters!\n";
    }

    else
    {
        Executive exec(argv[1]);
        exec.run();
    }

    return 0;
}