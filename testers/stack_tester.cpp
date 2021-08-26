//
// Created by Lonmouth Mallador on 7/12/21.
//

#include <fstream>
#include <iostream>
#include <stack>
#include "Stack.hpp"

void test_top() {
    std::ofstream my_output;
    std::ofstream std_output;

    my_output.open(MY_OUTPUT);
    std_output.open(STD_OUTPUT);
    std::cout << "Test top()" << std::endl;
    {
        std::stack<int> mystack;

        mystack.push(10);
        mystack.push(20);

        mystack.top() -= 5;

        std_output << "mystack.top() is now " << mystack.top();
    }
    {
        ft::stack<int> mystack;

        mystack.push(10);
        mystack.push(20);

        mystack.top() -= 5;

        my_output << "mystack.top() is now " << mystack.top();
    }
    my_output.close();
    std_output.close();
    check_diff();
}

void test_push() {
    std::ofstream my_output;
    std::ofstream std_output;

    my_output.open(MY_OUTPUT);
    std_output.open(STD_OUTPUT);
    std::cout << "Test push()" << std::endl;
    {
        std::stack<int> mystack;

        for (int i=0; i<5; ++i) mystack.push(i);

        while (!mystack.empty())
        {
            std_output << mystack.top();
            mystack.pop();
        }
    }
    {
        ft::stack<int> mystack;

        for (int i=0; i<5; ++i) mystack.push(i);

        while (!mystack.empty())
        {
            my_output << mystack.top();
            mystack.pop();
        }
    }
    my_output.close();
    std_output.close();
    check_diff();
}

void test_pop() {
    std::ofstream my_output;
    std::ofstream std_output;

    my_output.open(MY_OUTPUT);
    std_output.open(STD_OUTPUT);
    std::cout << "Test pop()" << std::endl;
    {
        std::stack<int> mystack;

        for (int i=0; i<5; ++i) mystack.push(i);

        while (!mystack.empty())
        {
            std_output << mystack.top();
            mystack.pop();
        }
    }
    {
        ft::stack<int> mystack;

        for (int i=0; i<5; ++i) mystack.push(i);

        while (!mystack.empty())
        {
            my_output << mystack.top();
            mystack.pop();
        }
    }
    my_output.close();
    std_output.close();
    check_diff();
}

void make_stack_test() {
    std::cout << MAGENTA << "\n\n-------------------------------" << std::endl;
    std::cout << "     STACK TESTER STARTED" << std::endl;
    std::cout << "-------------------------------" << RESET << std::endl;

    test_top();
    test_push();
    test_pop();
}