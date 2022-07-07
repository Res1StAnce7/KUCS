#include <iostream>
#include "Node.h"
#include "Queue.h"
#define pi 3.14
using namespace std;

double dangerous(double n1)
{
    if(n1 == 0)
    {
        return (pi);
    }

    else
    {
        throw(runtime_error("Error"));
    }
}

int main()
{
    double num = 0;
    double ans = 0;
    bool a = 0;
    do
    {

        cout << "Input a number: ";
        cin >> num;
        try
        {
            ans = dangerous(num); //As soon as an exception is thrown,
            cout << ans << endl;  //go will catch the block and skip the remaining code
            cout << "Phew! That was risky!" << endl;
            a = 1;
        }

        catch (runtime_error &rte)
        {
            cout << rte.what() << endl; //Only runs if an exception is thrown
        }                               //in the try block

    } while(a != 1);
    return(0);
}