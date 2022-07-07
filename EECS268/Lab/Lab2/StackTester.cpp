/**
 * @file StackTester.cpp
 * @author Siliang Zhang
 * @brief This file will run a few tests to make sure the stack is working.
 * @date 2021-03-03
 */
#include <iostream>
#include "StackTester.h"
#include "StackofChars.h"
using namespace std;

StackTester::StackTester()
{
    test01();
    test02();
    test03();
    test04();
    test05();
    test06();
}

void StackTester::runTests()
{
    void test01();
    void test02();
    void test03();
    void test04();
    void test05();
    void test06();
}

void StackTester::test01()
{
    StackofChars Stack1;
    if(Stack1.isEmpty())
    {
       cout << "Test #1: New stack is empty: PASSED" << endl;
    }

    else
    {
        cout << "Test #1: New stack is empty: FAILED" << endl;
    }  
}

void StackTester::test02()
{
    StackofChars Stack2;

    Stack2.push('a');

    if(Stack2.isEmpty())
    {
        cout << "Test #2: Pushing on empty stack makes it non-empty: FAILED" << endl;
    }

    else
    {
        cout << "Test #2: Pushing on empty stack makes it non-empty: PASSED" << endl;
    }
}

void StackTester::test03()
{
    StackofChars Stack3;
    Stack3.push('a');
    Stack3.pop();

    if(Stack3.isEmpty())
    {
        cout << "Test #3: Popping all elements makes stack empty: PASSED" << endl;
    }

    else
    {
        cout << "Test #3: Popping all elements makes stack empty: FAILED" << endl;
    }
}

void StackTester::test04()
{
    StackofChars Stack4;

    for(int i=0; i<7; i++){
        Stack4.push('a');
    }

    for(int i=0; i<4; i++){
        Stack4.pop();
    }

    if(Stack4.isEmpty())
    {
        cout << "Test #4: Pushing 7 elements and poping 3 elements makes stack non-empty: FAILED" << endl;
    }

    else
    {
        cout << "Test #4: Pushing 7 elements and poping 3 elements makes stack non-empty: PASSED" << endl;
    }

}

void StackTester::test05()
{
    StackofChars Stack5;
    for(int i=0; i<2; i++){
        Stack5.push('a');
    }

    for(int i=0; i<2; i++){
        Stack5.pop();
    }

    if(Stack5.isEmpty())
    {
        Stack5.push('a');
        if(Stack5.isEmpty())
        {
            cout << "Test #5: Pushing 2 elements, poping 2 elements makes stack empty, then pushing 1 element makes stack non-empty: FAILED" << endl;
        }

        else
        {
            cout << "Test #5: Pushing 2 elements, poping 2 elements makes stack empty, then pushing 1 element makes stack non-empty: PASSED" << endl;
        }
        
    }

    else
    {
        cout << "Test #5: Pushing 2 elements, poping 2 elements makes stack empty, then pushing 1 element makes stack non-empty: FAILED" << endl;
    }
}

void StackTester::test06()
{
    StackofChars Stack6;
    for(int i=0; i<3; i++){
        Stack6.push('a');
    }

    Stack6.pop();
    
    if(Stack6.isEmpty())
    {
        cout << "Test #6: Pushing 3 elements, poping 1 element makes stack non-empty, then poping 2 element makes stack empty: FAILED" << endl;   
    }

    else
    {
        for(int i=0; i<2; i++){
            Stack6.pop();
        }

        if(Stack6.isEmpty())
        {
            cout << "Test #6: Pushing 3 elements, poping 1 element makes stack non-empty, then poping 2 element makes stack empty: PASSED" << endl;
        }

        else
        {
            cout << "Test #6: Pushing 3 elements, poping 1 element makes stack non-empty, then poping 2 element makes stack empty: FAILED" << endl;
        }
    }   
}