//
// Created by Lonmouth Mallador on 7/12/21.
//
#include <fstream>
#include <iostream>
#include <map>
#include "Map.hpp"

void test_m_constructor() {
    std::ofstream my_output;
    std::ofstream std_output;

    my_output.open(MY_OUTPUT);
    std_output.open(STD_OUTPUT);
    std::cout << "Test default constructor..." << std::endl;
    {
        ft::map<int, std::string> m_my;
        std::map<int, std::string> m_std;

        m_my.insert(ft::pair<int, std::string>(1, "ff"));
        m_std.insert(std::pair<int, std::string>(1, "ff"));

        m_my.insert(ft::pair<int, std::string>(1, "gg"));
        m_std.insert(std::pair<int, std::string>(1, "gg"));
        m_my.insert(ft::pair<int, std::string>(2, "gg"));
        m_std.insert(std::pair<int, std::string>(2, "gg"));

        m_my.insert(ft::pair<int, std::string>(2, "22"));
        m_std.insert(std::pair<int, std::string>(2, "22"));

        m_my.insert(ft::pair<int, std::string>(3, "33"));
        m_std.insert(std::pair<int, std::string>(3, "33"));

        for (int i = 0; i < 5000; i++) {
            m_my.insert(ft::pair<int, std::string>(i, "c"));
            m_std.insert(std::pair<int, std::string>(i, "c"));
        }
        ft::map<int, std::string>::iterator m_begin = --m_my.end();
        std::map<int, std::string>::iterator std_begin = --m_std.end();

        for (; m_begin != m_my.begin(); m_begin--) {
            my_output << m_begin->second;
        }

        for (; std_begin != m_std.begin(); std_begin--)
            std_output << std_begin->second;

        m_begin = m_my.begin();
        std_begin = m_std.begin();

        for (; m_begin != m_my.end(); m_begin++)
            my_output << m_begin->second;

        for (; std_begin != m_std.end(); std_begin++)
            std_output << std_begin->second;


    }
    std::cout << "Test range constructor..." << std::endl;
    {
        ft::map<int, std::string> m_my;
        std::map<int, std::string> m_std;


        m_my.insert(ft::pair<int, std::string>(1, "ff"));
        m_std.insert(std::pair<int, std::string>(1, "ff"));

        m_my.insert(ft::pair<int, std::string>(1, "gg"));
        m_std.insert(std::pair<int, std::string>(1, "gg"));
        m_my.insert(ft::pair<int, std::string>(2, "gg"));
        m_std.insert(std::pair<int, std::string>(2, "gg"));

        m_my.insert(ft::pair<int, std::string>(2, "22"));
        m_std.insert(std::pair<int, std::string>(2, "22"));

        m_my.insert(ft::pair<int, std::string>(3, "33"));
        m_std.insert(std::pair<int, std::string>(3, "33"));

        for (int i = 0; i < 5000; i++) {
            m_my.insert(ft::pair<int, std::string>(i, "c"));
            m_std.insert(std::pair<int, std::string>(i, "c"));
        }
        ft::map<int, std::string> m_2_my(m_my.begin(), m_my.end());
        std::map<int, std::string> m_2_std(m_std.begin(), m_std.end());

        ft::map<int, std::string>::iterator m_begin = --m_2_my.end();
        std::map<int, std::string>::iterator std_begin = --m_2_std.end();

        for (; m_begin != m_2_my.begin(); m_begin--) {
            my_output << m_begin->second;
        }

        for (; std_begin != m_2_std.begin(); std_begin--)
            std_output << std_begin->second;

        m_begin = m_2_my.begin();
        std_begin = m_2_std.begin();

        for (; m_begin != m_2_my.end(); m_begin++)
            my_output << m_begin->second;

        for (; std_begin != m_2_std.end(); std_begin++)
            std_output << std_begin->second;

    }
    std::cout << "Test copy constructor..." << std::endl;
    {
        ft::map<int, std::string> m_my;
        std::map<int, std::string> m_std;


        m_my.insert(ft::pair<int, std::string>(1, "ff"));
        m_std.insert(std::pair<int, std::string>(1, "ff"));

        m_my.insert(ft::pair<int, std::string>(1, "gg"));
        m_std.insert(std::pair<int, std::string>(1, "gg"));
        m_my.insert(ft::pair<int, std::string>(2, "gg"));
        m_std.insert(std::pair<int, std::string>(2, "gg"));

        m_my.insert(ft::pair<int, std::string>(2, "22"));
        m_std.insert(std::pair<int, std::string>(2, "22"));

        m_my.insert(ft::pair<int, std::string>(3, "33"));
        m_std.insert(std::pair<int, std::string>(3, "33"));

        for (int i = 0; i < 5000; i++) {
            m_my.insert(ft::pair<int, std::string>(i, "c"));
            m_std.insert(std::pair<int, std::string>(i, "c"));
        }
        ft::map<int, std::string> m_2_my(m_my);
        std::map<int, std::string> m_2_std(m_std);

        ft::map<int, std::string>::iterator m_begin = --m_2_my.end();
        std::map<int, std::string>::iterator std_begin = --m_2_std.end();

        for (; m_begin != m_2_my.begin(); m_begin--) {
            my_output << m_begin->second;
        }

        for (; std_begin != m_2_std.begin(); std_begin--)
            std_output << std_begin->second;

        m_begin = m_2_my.begin();
        std_begin = m_2_std.begin();

        for (; m_begin != m_2_my.end(); m_begin++)
            my_output << m_begin->second;

        for (; std_begin != m_2_std.end(); std_begin++)
            std_output << std_begin->second;

    }

    my_output.close();
    std_output.close();
    check_diff();
}


void test_map_erase() {
    std::ofstream my_output;
    std::ofstream std_output;

    my_output.open(MY_OUTPUT);
    std_output.open(STD_OUTPUT);
    std::cout << "Test erase() *1" << std::endl;
    {
        ft::map<int, std::string> m_my;
        std::map<int, std::string> m_std;

        m_my.insert(ft::pair<int, std::string>(1, "ff"));
        m_std.insert(std::pair<int, std::string>(1, "ff"));

        m_my.insert(ft::pair<int, std::string>(1, "gg"));
        m_std.insert(std::pair<int, std::string>(1, "gg"));
        m_my.insert(ft::pair<int, std::string>(2, "gg"));
        m_std.insert(std::pair<int, std::string>(2, "gg"));

        m_my.insert(ft::pair<int, std::string>(2, "22"));
        m_std.insert(std::pair<int, std::string>(2, "22"));

        m_my.insert(ft::pair<int, std::string>(3, "33"));
        m_std.insert(std::pair<int, std::string>(3, "33"));

        m_my.insert(ft::pair<int, std::string>(-3, "334"));
        m_std.insert(std::pair<int, std::string>(-3, "334"));

        for (int i = 0; i < 2000; i++) {
            m_my.insert(ft::pair<int, std::string>(i, "c"));
            m_std.insert(std::pair<int, std::string>(i, "c"));
        }

        ft::map<int, std::string>::iterator m_begin = m_my.begin();
        std::map<int, std::string>::iterator std_begin = m_std.begin();

        for (; m_begin != m_my.end(); m_begin++) {
            m_my.erase(m_begin);
            m_begin = m_my.begin();
            my_output << m_my.size();
        }

        for (; std_begin != m_std.end(); std_begin++) {
            m_std.erase(std_begin);
            std_begin = m_std.begin();
            std_output << m_std.size();
        }
    }
    std::cout << "Test erase() *2" << std::endl;
    {
        ft::map<int, std::string> m_my;
        std::map<int, std::string> m_std;

        m_my.insert(ft::pair<int, std::string>(1, "ff"));
        m_std.insert(std::pair<int, std::string>(1, "ff"));

        m_my.insert(ft::pair<int, std::string>(1, "gg"));
        m_std.insert(std::pair<int, std::string>(1, "gg"));
        m_my.insert(ft::pair<int, std::string>(2, "gg"));
        m_std.insert(std::pair<int, std::string>(2, "gg"));

        m_my.insert(ft::pair<int, std::string>(2, "22"));
        m_std.insert(std::pair<int, std::string>(2, "22"));

        m_my.insert(ft::pair<int, std::string>(3, "33"));
        m_std.insert(std::pair<int, std::string>(3, "33"));

        m_my.insert(ft::pair<int, std::string>(-3, "334"));
        m_std.insert(std::pair<int, std::string>(-3, "334"));

        for (int i = 0; i < 2000; i++) {
            m_my.insert(ft::pair<int, std::string>(i, "c"));
            m_std.insert(std::pair<int, std::string>(i, "c"));
        }

        ft::map<int, std::string>::iterator m_begin = m_my.begin();
        std::map<int, std::string>::iterator std_begin = m_std.begin();

        for (; m_begin != m_my.end(); m_begin++) {
            m_my.erase(m_begin->first);
            m_begin = m_my.begin();
            my_output << m_my.size();
        }

        for (; std_begin != m_std.end(); std_begin++) {
            m_std.erase(std_begin->first);
            std_begin = m_std.begin();
            std_output << m_std.size();
        }
    }
    std::cout << "Test erase() *3" << std::endl;
    {
        ft::map<int, std::string> m_my;
        std::map<int, std::string> m_std;

        for (int i = 0; i < 2000; i++) {
            m_my.insert(ft::pair<int, std::string>(i, "c"));
            m_std.insert(std::pair<int, std::string>(i, "c"));
        }

        m_my.erase(m_my.begin(), m_my.end());
        m_std.erase(m_std.begin(), m_std.end());

        my_output << m_my.size();
        std_output << m_std.size();
    }

    my_output.close();
    std_output.close();
    check_diff();
}

void test_map_swap() {
    std::ofstream my_output;
    std::ofstream std_output;

    my_output.open(MY_OUTPUT);
    std_output.open(STD_OUTPUT);
    std::cout << "Test swap()" << std::endl;
    {
        ft::map<int, std::string> m_my;
        std::map<int, std::string> m_std;
        ft::map<int, std::string> m_2_my;
        std::map<int, std::string> m_2_std;

        m_my.insert(ft::pair<int, std::string>(1, "ff"));
        m_std.insert(std::pair<int, std::string>(1, "ff"));

        m_my.insert(ft::pair<int, std::string>(1, "gg"));
        m_std.insert(std::pair<int, std::string>(1, "gg"));
        m_my.insert(ft::pair<int, std::string>(2, "gg"));
        m_std.insert(std::pair<int, std::string>(2, "gg"));

        m_my.insert(ft::pair<int, std::string>(2, "22"));
        m_std.insert(std::pair<int, std::string>(2, "22"));

        m_my.insert(ft::pair<int, std::string>(3, "33"));
        m_std.insert(std::pair<int, std::string>(3, "33"));

        m_my.insert(ft::pair<int, std::string>(-3, "334"));
        m_std.insert(std::pair<int, std::string>(-3, "334"));

        for (int i = 0; i < 2000; i++) {
            m_2_my.insert(ft::pair<int, std::string>(i, "c"));
            m_2_std.insert(std::pair<int, std::string>(i, "c"));
        }


        m_my.swap(m_2_my);
        m_std.swap(m_2_std);

        ft::map<int, std::string>::iterator m_begin = m_my.begin();
        std::map<int, std::string>::iterator std_begin = m_std.begin();

        ft::map<int, std::string>::iterator m_2_begin = m_2_my.begin();
        std::map<int, std::string>::iterator std_2_begin = m_2_std.begin();

        for (; m_begin != m_my.end(); m_begin++) {
            my_output << m_begin->first;
        }

        for (; std_begin != m_std.end(); std_begin++) {
            std_output << std_begin->first;
        }

        for (; m_2_begin != m_2_my.end(); m_2_begin++) {
            my_output << m_2_begin->first;
        }

        for (; std_2_begin != m_2_std.end(); std_2_begin++) {
            std_output << std_2_begin->first;
        }
    }

    my_output.close();
    std_output.close();
    check_diff();
}

void test_upper_lower() {
    std::ofstream my_output;
    std::ofstream std_output;

    my_output.open(MY_OUTPUT);
    std_output.open(STD_OUTPUT);
    std::cout << "Test upper_bound() lower_bound()" << std::endl;
    {
        ft::map<int, std::string> m_my;
        std::map<int, std::string> m_std;

        for (int i = 1; i < 900; i++) {
            m_my.insert(ft::pair<int, std::string>(i, "c"));
            m_std.insert(std::pair<int, std::string>(i, "c"));
        }

        ft::map<int, std::string>::iterator m_begin = m_my.begin();
        std::map<int, std::string>::iterator std_begin = m_std.begin();

        for (; m_begin != m_my.end(); m_begin++) {
            my_output << m_my.upper_bound(m_begin->first)->first;
            my_output << m_my.lower_bound(m_begin->first)->first;
        }

        for (; std_begin != m_std.end(); std_begin++) {
            std_output << m_std.upper_bound(std_begin->first)->first;
            std_output << m_std.lower_bound(std_begin->first)->first;
        }
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
    test_map_erase();
    test_map_swap();
    test_upper_lower();
}