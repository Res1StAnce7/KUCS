#include <iostream>
using namespace std;

double myDiv(double n1, double n2)
{
    if(n2 != 0){
        return(n1/n2);
    }

    else{
        throw(runtime_error("Division by zero!"));
    }   
}

double middleMan(double n1, double n2)
{
    double ans = myDiv(n1,n2);
    printf("The middleMan is about to return!\n");
    return ans;
}

int main()
{
    double ans = 0;
    
    try{
        ans = middleMan(-10,1);    //As soon as an exception is thrown,
        printf("%.1f\n",ans);  //go will catch the block and skip the remaining code
        printf("Phew! That was risky!\n");
    }

    catch(runtime_error& rte){
        printf("%s\n",rte.what());  //Only runs if an exception is thrown
    }                               //in the try block
    
    return 0;
}