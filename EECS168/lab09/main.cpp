#include <iostream>
#include <fstream>
using namespace std;

void printMenu()
{
    cout << "Make a selection:" << '\n';
    cout << "1) Insert" << '\n';
    cout << "2) Remove" << '\n';
    cout << "3) Count" << '\n';
    cout << "4) Print " << '\n';
    cout << "5) Exit" << '\n';
    cout << "Choice: ";
}

int *insert(int arr[], int &size, int value, int position)
{

    int *ins = nullptr;
    ins = new int[size + 1];

    int i;
    for (i = 0; i < position; i++)
    {

        ins[i] = arr[i];
    }
    ins[i] = value;
    for (int i = position + 1; i < size + 1; i++)
    {

        ins[i] = arr[i - 1];
    }

    delete[] arr;
    return (ins);
}

int *remove(int arr[], int &size, int position)
{

    int *rem = nullptr;
    rem = new int[size - 1];

    if (position != 0)
    {

        for (int i = 0; i < position; i++)
        {

            rem[i] = arr[i];
        }
        for (int i = position; i < size - 1; i++)
        {

            rem[i] = arr[i + 1];
        }
    }

    else if (position == 0)
    {
        for (int i = 0; i < size - 1; i++)
        {
            rem[i] = arr[i + 1];
        }
    }
    delete[] arr;
    return (rem);
}

int count(int arr[], int size, int target)
{
    int ct = 0;

    for (int i = 0; i < size; i++)
    {

        if (arr[i] == target)
        {

            ct++;
        }
    }

    return (ct);
}

void print(int arr[], int size) {
    cout << "[";

    for (int i = 0; i < size; i++)
    {

        cout << arr[i];

        if (i != size - 1)
        {

            cout << ", ";
        }
    }
    cout << "]";
}

int main(int argc, char **argv) {

    string filename;
    string size0;
    if (argc > 1)
    {
        filename = argv[1];
        size0 = argv[2];
    }

    ifstream inFile;       // create a variable of type ifstream. It will enable reading from files.
    inFile.open(filename); // open a file that has values in it

    // Check if file is open
    if (inFile.is_open())
    {

        int choice, position, ct;
        double value, target;
        int *num = nullptr;
        int size = 0;
        size = stoi(size0);
        num = new int[size];

        for (int i = 0; i < size; i++)
        {
            inFile >> num[i];
        }

        do
        {
            printMenu();
            cin >> choice;
            do
            {
                if (cin.fail())
                {

                    cin.clear();
                    cin.ignore();
                    cout << "Error----please input a valid choice: ";
                    cin >> choice;
                }
                else if (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5)
                {

                    cout << "Error----please input a valid postion: ";
                    cin >> choice;
                }
            } while (cin.fail() || (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5));

            if (choice == 1)
            {

                cout << "From 0 to " << size - 1 << ", where do you want to insert the value? ";
                cin >> position;
                do
                {
                    if (cin.fail())
                    {

                        cin.clear();
                        cin.ignore();
                        cout << "Error----please input a valid postion: ";
                        cin >> position;
                    }

                    else if (position < 0 || position > size - 1)
                    {

                        cout << "Error----please input a valid postion: ";
                        cin >> position;
                    }
                } while (cin.fail() || (position < 0 || position > size - 1));

                cout << "Please input the value you want to insert: ";
                cin >> value;
                do
                {

                    if (cin.fail())
                    {

                        cin.clear();
                        cin.ignore();
                        cout << "Error----please input a valid value: ";
                        cin >> value;
                    }
                } while (cin.fail());

                num = insert(num, size, value, position);
                size++;
            }
            if (choice == 2)
            {

                cout << "From 0 to " << size - 1 << ", input the position of the value you want to remove: ";
                cin >> position;
                do
                {

                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore();
                        cout << "Error----please input a valid postion: ";
                        cin >> position;
                    }

                    else if (position < 0 || position > size - 1)
                    {
                        cout << "Error----please input a valid postion: ";
                        cin >> position;
                    }
                } while (cin.fail() || (position < 0 || position > size - 1));

                num = remove(num, size, position);
                size--;
            }

            if (choice == 3)
            {
                cout << "Please input a value: ";
                cin >> target;
                do
                {
                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore();
                        cout << "Error----please input a valid postion: ";
                        cin >> target;
                    }
                } while (cin.fail());

                ct = count(num, size, target);
                cout << "" << target << " shows " << ct << " time(s) in the array." << '\n';
            }

            if (choice == 4)
            {
                print(num, size);
                cout << '\n';
            }

        } while (choice != 5);
        delete[] num;
        return (0);
    }
    else
    {
        cout << "File could not be opened!\n";
        system("pause");
        return (0);
    }
}