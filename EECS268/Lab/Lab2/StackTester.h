/**
 * @file StackTester.h
 * @author Siliang Zhang
 * @brief It is the header file of StackTester.cpp
 * @date 2021-03-03
 */
#ifndef STACKTESTER_H
#define STACKTESTER_H

class StackTester
{   
    public: 

    StackTester();

    void runTests();
     
    private:

    /**
    * @brief Creates an empty stack and verifies isEmpty() returns true
    **/
    void test01();

    /**
    * @brief Creates an empty stack pushes 1 value, verifies isEmpty() returns false
    **/
    void test02();

    /**
    * @brief Creates an empty stack, then pushes once, pops once, and verifies isEmpty returns true
    **/
    void test03();
    
    /**
    * @brief Creates an empty stack, then pushes seven times, pops three times, and verifies isEmpty returns false
    **/
    void test04();

    /**
    * @brief Creates an empty stack, pushes two times, pops two times, verifies isEmpty returns true, then pushes once and verifies isEmpty returns false
    **/
    void test05();

    /**
    * @brief Creates an empty stack, pushes three times, pops once, verifies isEmpty returns false, then pops twice and verifies isEmpty returns true
    **/
    void test06();

};
#endif