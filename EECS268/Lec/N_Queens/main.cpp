#include <iostream>
#include <math.h>
using namespace std;

int num = 0;
int q[26];	

void print(int n)
{
	int i, j;
	cout << "Solution " << ++num << ":";

	for (i = 1; i <= n; i++)
	{
		cout << "("<<i<<","<<q[i]<<")";
	}
	cout << endl;

	for (i = 1; i <= n; i++) 
	{
		for (j = 1; j <= n; j++) 
		{
			if (q[i] != j)
			{
				cout << ". ";
			}
			else
			{
				cout << "Q ";
			}
		}
		cout << endl;
	}
}

bool isValid(int row, int col)
{
	int i = 1;
	while (i < row) 
	{
		if (q[i] == col || abs(i - row) == abs(q[i] - col)) 
		{	
			return false;
		}
		i++;
	}
	return true;
}

void place(int row, int size)
{
	if (row > size)
	{
		print(size);
		cout << endl;
	}

	else
	{
		for (int i = 1; i <= size; i++) 
		{
			if (isValid(row, i))
			{
				q[row] = i;
				place(row + 1, size); 
			}
		}
	}
}

int main()
{ 
	int size;
	int choice;
		
	do
 	{
		cout << "N-Queens Solver" << endl;
		cout << "User Menu" << endl;
		cout << "#1 4-Queens"<< endl;
		cout << "#2 8-Queens"<< endl;
		cout << "#3 N-Queens (8<N<101)" << endl;
		cout << "#4 Exit" << endl;
		cout << "Please input your choice: ";
		cin >> choice;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "Invalid choice! Please try again!" << endl;
		}

		else if(choice == 1)
		{
			cout << "Here is the solution to 4-Queens" << endl;
			place(1,4);
		}

		else if(choice == 2)
		{
			cout << "Here is the solution to 8-Queens" << endl;
			place(1,8);
		}

		else if(choice == 3)
		{	
			do
			{
				cout << "How many Queens do you want to place? Please input a number within 8 to 26: ";
				cin >> size;

				if(cin.fail())
				{
					cin.clear();
					cin.ignore();
					cout << "Invalid size! Please try again!" << endl;
				}

				else if(size < 9 || size > 25)
				{
					cout << "Invalid size! Please try again!" << endl;
				}
			} while (cin.fail() || size < 9 || size > 25);
			
			cout << "Here is the solution to "<<size<<"-Queens" << endl;
			place(1,size);        
		}
	}while(cin.fail() || choice > 4 || choice < 1 || choice != 4);	

	system("pause");
	return 0;
}

