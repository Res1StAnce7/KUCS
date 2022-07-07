/**
 * @file main.cpp
 * @author Siliang Zhang
 * @brief This file will be able to create stacks and check if they are functional.
 * @brief Also it will allow the user to enter a single string consisting of left and right curly braces
 * @brief and verify whether not the sequence is balanced or not.
 * @date 2021-03-03
 */
#include <iostream>
#include <string>
#include "Node.h"
#include "StackofChars.h"
#include "StackTester.h"
using namespace std;

int main(int argc, char **argv) {
    if (argc < 2) {
        cout << "Incorrect number of parameters!\n";
    }
    else {
        string lineCommand = argv[1];

        if (lineCommand.compare("-t") == 0) {
            StackTester run;
            run.runTests();
        }
        else if (lineCommand.compare("-p") == 0) {
            StackofChars Stack;
            bool balance;
            string sequence;

            cout << "Enter your sequence: ";
            cin >> sequence;

            if (sequence.length() % 2 != 0) {
                cout << "Sequence is not balanced." << endl;
            }
            else if (sequence.length() % 2 == 0) {
                for (unsigned int i = 0; i < sequence.length(); i++) {
                    if (sequence[i] == '{') {
                        balance = 0;
                        Stack.push(sequence[i]);
                    }
                    else if (sequence[i] == '}') {
                        if (Stack.isEmpty()) {
                            balance = false;
                            break;
                        }
                        else if (!Stack.isEmpty()) {
                            balance = true;
                            Stack.pop();
                        }
                    }
                }
                if (balance) {
                    cout << "Sequence is balanced." << endl;
                }
                else {
                    cout << "Sequence is not balanced." << endl;
                }

                Stack.clear();
            }
        }
        else {
            cout << "Wrong command!" << endl;
        }
    }

    return 0;
}