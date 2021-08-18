//
// Created by Lonmouth Mallador on 7/12/21.
//
#include <fstream>
#include <iostream>
#include <map>
#include "Map.hpp"

#define MY_OUTPUT "my_output"
#define STD_OUTPUT "std_output"

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

void test_m_constructor() {
    std::ofstream my_output;
    std::ofstream std_output;

    my_output.open(MY_OUTPUT);
    std_output.open(STD_OUTPUT);
    std::cout << "Test default constructor..." << std::endl;
    {
        ft::map<int, std::string> m_my;
        std::map<int, std::string> m_std;

        m_my.insert(std::pair<int, std::string>(1, "ff"));
        m_std.insert(std::pair<int, std::string>(1, "ff"));
        m_my.insert(std::pair<int, std::string>(9, "ff"));
        m_std.insert(std::pair<int, std::string>(9, "ff"));
        m_my.insert(std::pair<int, std::string>(3, "ff"));
        m_std.insert(std::pair<int, std::string>(3, "ff"));
        m_my.insert(std::pair<int, std::string>(5, "ff"));
        m_std.insert(std::pair<int, std::string>(5, "ff"));
    }

    my_output.close();
    std_output.close();
    check_diff();
}


void make_map_test() {
    std::cout << MAGENTA << "\n\n-------------------------------" << std::endl;
    std::cout << "     MAP TESTER STARTED" << std::endl;
    std::cout << "-------------------------------" << RESET << std::endl;

    test_m_constructor();
}