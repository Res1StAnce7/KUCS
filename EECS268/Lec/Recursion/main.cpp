#include <iostream>
using namespace std;

//when a function calls itself
void recFunc(int i)
{
    if(i <= 5)
    {  
        recFunc(i+1); //i=6 is still passed in and the if doesn't work, then the function pops off
        cout << i << endl;
        cout << "leaving call#"<<i<<"" << endl;
    }   
}

int factorial(int n)
{
    if(n == 1)
    { 
        cout << n << endl;
        return(1);   
    }

    else
    {
        cout << n << endl;
        return(n*factorial(n-1));
    }
}

double recSum(double arr[], int size)
{
    if (size > 1)
    {
    	return(arr[size-1]+recSum(arr, size-1));
    }
    
    else if (size == 1)
    {
		return(arr[0]);
    }

    else
    {
	    throw(runtime_error("Invalid size\n"));
    }

}

bool allEven(int arr[], int size)
{
    if (size > 1)
    {
    	return(arr[size-1] % 2 == 1 && allEven(arr,size-1));
    }
    
    else if (size == 1)
    {
		if(arr[0] % 2 == 1)
        {
            return(true);
        }

        else
        {
            return(false);
        }
    }

    else
    {
	    throw(runtime_error("Invalid size\n"));
    }
}

bool isPalindrome(char arr[], int size)
{
    if(size == 1)
    {
        return(true);
    }

    else if(size > 1) 
    {
        return(arr[0]==arr[size-1] && isPalindrome(arr+1,size-2));
    }
    
    else
    {
	    throw(runtime_error("Invalid size\n"));
    }
}

int main()
{
    bool check;
    int a[2];
    a[0] = 3;
    a[1] = 9;

    try
    {
        check = allEven(a,2);
        cout << check << endl;
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
    }
    
    char b[7];
    b[0] = 't';
    b[1] = 'a';
    b[2] = 'c';
    b[3] = 'o';
    b[4] = 'c';
    b[5] = 'a';
    b[6] = 't';

    char *c = b + 1;
    try
    {
        check = isPalindrome(b,7);
        cout << check << endl;
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
    }

    cout << c[0] << endl;
    return 0;
}
