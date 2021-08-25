//
// Created by Lonmouth Mallador on 7/12/21.
//

#include <fstream>
#include <iostream>
#include <vector>
#include "../containers/Vector.hpp"

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

void check_diff() {
    std::ifstream my_output;
    std::ifstream std_output;

    my_output.open(MY_OUTPUT);
    std_output.open(STD_OUTPUT);
    std::string my, std;
    std::cout << "Result: ";
    if (my_output.is_open() && std_output.is_open()) {
        while (std::getline(my_output, my) && std::getline(std_output, std)) {
            if (my == std) {
                std::cout << BOLDGREEN << "OK" << RESET << std::endl;
            } else {
                std::cout << BOLDRED << "KO" << RESET << std::endl;
                break;
            }
        }
        if (my != std)
            std::cout << BOLDRED << "KO" << RESET << std::endl;

        my_output.close();
        std_output.close();
//        std::remove(MY_OUTPUT);
//        std::remove(STD_OUTPUT);
    } else {
        std::cout << BOLDRED << "KO" << RESET << std::endl;
    }
}

void test_constructor() {
    std::ofstream my_output;
    std::ofstream std_output;

    my_output.open(MY_OUTPUT);
    std_output.open(STD_OUTPUT);
    std::cout << "Test default constructor..." << std::endl;
    {
        ft::vector<int> v_my;
        std::vector<int> v_std;
        v_my.push_back(1);
        v_std.push_back(1);
        v_my.push_back(2);
        v_std.push_back(2);
        v_my.push_back(3);
        v_std.push_back(3);
        ft::vector<int>::iterator my_i = v_my.begin();
        std::vector<int>::iterator std_i = v_std.begin();
        for (; my_i != v_my.end(); my_i++)
            my_output << *my_i;
        for (; std_i != v_std.end(); std_i++)
            std_output << *std_i;
    }
    std::cout << "Test fill constructor..." << std::endl;
    {
        size_t n = 5000;
        ft::vector<int> v_my(n, 999999);
        std::vector<int> v_std(n, 999999);

        ft::vector<int>::iterator my_i = v_my.begin();
        std::vector<int>::iterator std_i = v_std.begin();
        for (; my_i != v_my.end(); my_i++)
            my_output << *my_i;
        for (; std_i != v_std.end(); std_i++)
            std_output << *std_i;

        std::cout << "Test range constructor..." << std::endl;
        for (int i = 0; i < 10; i++) {
            v_my.push_back(i);
            v_std.push_back(i);
        }
        ft::vector<int> v_2_my(v_my.begin(), v_my.end());
        std::vector<int> v_2_std(v_std.begin(), v_std.end());
        ft::vector<int>::iterator my_2_i = v_2_my.begin();
        std::vector<int>::iterator std_2_i = v_2_std.begin();
        for (; my_2_i != v_2_my.end(); my_2_i++)
            my_output << *my_2_i;
        for (; std_2_i != v_2_std.end(); std_2_i++)
            std_output << *std_2_i;

        std::cout << "Test copy constructor..." << std::endl;

        ft::vector<int> v_3_my(v_my);
        std::vector<int> v_3_std(v_std);
        ft::vector<int>::iterator my_3_i = v_3_my.begin();
        std::vector<int>::iterator std_3_i = v_3_std.begin();
        for (; my_3_i != v_3_my.end(); my_3_i++)
            my_output << *my_3_i;
        for (; std_3_i != v_3_std.end(); std_3_i++)
            std_output << *std_3_i;
    }
    my_output.close();
    std_output.close();
    check_diff();
}

void test_emty() {
    std::ofstream my_output;
    std::ofstream std_output;

    my_output.open(MY_OUTPUT);
    std_output.open(STD_OUTPUT);
    std::cout << "Test empty() function" << std::endl;
    size_t n = 5000;
    ft::vector<int> v_my(n, 999999);
    std::vector<int> v_std(n, 999999);
    my_output << v_my.size() << v_my.empty();
    std_output << v_std.size() << v_std.empty();
    v_my.erase(v_my.begin(), v_my.end());
    v_std.erase(v_std.begin(), v_std.end());
    my_output << v_my.size() << v_my.empty();
    std_output << v_std.size() << v_std.empty();
    my_output.close();
    std_output.close();
    check_diff();
}

void test_operator() {
    std::ofstream my_output;
    std::ofstream std_output;

    my_output.open(MY_OUTPUT);
    std_output.open(STD_OUTPUT);
    std::cout << "Test operator[]" << std::endl;
    size_t n = 5000;
    ft::vector<int> v_my(n, 999999);
    std::vector<int> v_std(n, 999999);
    for (int i = 0; i < n; i++) {
        my_output << v_my[i];
        std_output << v_std[i];
    }
    my_output.close();
    std_output.close();
    check_diff();
}

void test_at() {
    std::ofstream my_output;
    std::ofstream std_output;

    my_output.open(MY_OUTPUT);
    std_output.open(STD_OUTPUT);
    std::cout << "Test at" << std::endl;
    size_t n = 5000;
    ft::vector<int> v_my(n, 999999);
    std::vector<int> v_std(n, 999999);
    for (int i = 0; i < n; i++) {
        my_output << v_my.at(i);
        std_output << v_std.at(i);
    }
    my_output.close();
    std_output.close();
    check_diff();
}

void test_front() {
    std::ofstream my_output;
    std::ofstream std_output;

    my_output.open(MY_OUTPUT);
    std_output.open(STD_OUTPUT);
    std::cout << "Test front" << std::endl;
    size_t n = 5000;
    ft::vector<int> v_my(n, 999999);
    std::vector<int> v_std(n, 999999);
    for (int i = 0; i < n - 1; i++) {
        my_output << v_my.front();
        std_output << v_std.front();
        v_my.erase(v_my.begin());
        v_std.erase(v_std.begin());
    }
    my_output.close();
    std_output.close();
    check_diff();
}

void test_back() {
    std::ofstream my_output;
    std::ofstream std_output;

    my_output.open(MY_OUTPUT);
    std_output.open(STD_OUTPUT);
    std::cout << "Test back" << std::endl;
    size_t n = 5000;
    ft::vector<int> v_my(n, 999999);
    std::vector<int> v_std(n, 999999);
    for (int i = 0; i < n - 1; i++) {
        my_output << v_my.back();
        std_output << v_std.back();
        v_my.erase(v_my.begin());
        v_std.erase(v_std.begin());
    }
    my_output.close();
    std_output.close();
    check_diff();
}

void test_assign() {
    std::ofstream my_output;
    std::ofstream std_output;

    my_output.open(MY_OUTPUT);
    std_output.open(STD_OUTPUT);
    std::cout << "Test assign" << std::endl;
    {
        std::cout << "Test range (1) assign..." << std::endl;
        size_t n = 5000;
        ft::vector<int> v_my(n, 999999);
        std::vector<int> v_std(n, 999999);
        ft::vector<int> v_2_my(100, 300);
        std::vector<int> v_2_std(100, 300);
        v_2_my.assign(v_my.begin(), v_my.end());
        v_2_std.assign(v_std.begin(), v_std.end());

        for (int i = 0; i < n; i++) {
            my_output << v_my[i];
            std_output << v_std[i];
        }
    }
    {
        std::cout << "Test fill (2) assign..." << std::endl;
        size_t n = 5000;
        ft::vector<int> v_my(n, 999999);
        std::vector<int> v_std(n, 999999);
        v_my.assign(n * 2, 20000);
        v_std.assign(n * 2, 20000);

        for (int i = 0; i < n; i++) {
            my_output << v_my[i];
            std_output << v_std[i];
        }
    }
    my_output.close();
    std_output.close();
    check_diff();
}

void test_push_back() {
    std::ofstream my_output;
    std::ofstream std_output;

    my_output.open(MY_OUTPUT);
    std_output.open(STD_OUTPUT);
    std::cout << "Test push back" << std::endl;
    size_t n = 5000;
    ft::vector<int> v_my(n, 999999);
    std::vector<int> v_std(n, 999999);
    for (int i = 0; i < n * 2; i++) {
        v_my.push_back(i);
        v_std.push_back(i);
    }
    for (int i = 0; i < n * 2; i++) {
        my_output << v_my[i];
        std_output << v_std[i];
    }
    my_output.close();
    std_output.close();
    check_diff();
}

void test_pop_back() {
    std::ofstream my_output;
    std::ofstream std_output;

    my_output.open(MY_OUTPUT);
    std_output.open(STD_OUTPUT);
    std::cout << "Test pop_back()" << std::endl;
    size_t n = 5000;
    ft::vector<int> v_my(n, 999999);
    std::vector<int> v_std(n, 999999);
    for (int i = 0; i < n; i++) {
        v_my.pop_back();
        v_std.pop_back();
        my_output << v_my.back();
        std_output << v_std.back();
    }
    my_output.close();
    std_output.close();
    check_diff();
}

void test_insert() {
    std::ofstream my_output;
    std::ofstream std_output;

    my_output.open(MY_OUTPUT);
    std_output.open(STD_OUTPUT);
    std::cout << "Test insert" << std::endl;
    {
        std::cout << "Test single element (1) insert..." << std::endl;

        size_t n = 5000;
        ft::vector<int> v_my;
        std::vector<int> v_std;
        for (int i = 0; i < n; i++) {
            v_my.insert(v_my.begin(), i);
            v_std.insert(v_std.begin(), i);
        }
        v_my.insert(v_my.begin() + 1000, 99999);
        v_std.insert(v_std.begin() + 1000, 99999);
        for (int i = 0; i < n; i++) {
            my_output << v_my[i];
            std_output << v_std[i];
        }
    }
    {
        std::cout << "Test fill (2) insert..." << std::endl;

        size_t n = 5000;
        ft::vector<int> v_my(n, 999999);
        std::vector<int> v_std(n, 999999);

        v_my.insert(v_my.begin() + 1000, 99999);
        v_std.insert(v_std.begin() + 1000, 99999);
        for (int i = 0; i < n; i++) {
            my_output << v_my[i];
            std_output << v_std[i];
        }
    }
    {
        std::cout << "Test range (3) insert..." << std::endl;

        size_t n = 50;
        ft::vector<int> v_my(4, 1);
        std::vector<int> v_std(4, 1);
        ft::vector<int> v_2_my(n, 8);
        std::vector<int> v_2_std(n, 8);

        v_my.insert(v_my.begin(), n, 1);
        v_std.insert(v_std.begin(), n, 1);
        v_my.insert(v_my.begin() + 3, 99999);
        v_std.insert(v_std.begin() + 3, 99999);

        v_my.insert(v_my.begin() + 2, v_2_my.begin(), v_2_my.end());
        v_std.insert(v_std.begin() + 2, v_2_std.begin(), v_2_std.end());

        for (int i = 0; i < n; i++) {
            my_output << v_my[i];
            std_output << v_std[i];
        }
    }
    my_output.close();
    std_output.close();
    check_diff();
}


void test_erase() {
    std::ofstream my_output;
    std::ofstream std_output;

    my_output.open(MY_OUTPUT);
    std_output.open(STD_OUTPUT);
    std::cout << "Test erase()" << std::endl;
    {
        std::cout << "Test erase with iterator position..." << std::endl;

        size_t n = 5000;
        ft::vector<int> v_my(n, 999999);
        std::vector<int> v_std(n, 999999);

        v_my.erase(v_my.begin());
        v_std.erase(v_std.begin());
        my_output << v_my.size();
        std_output << v_std.size();
        v_my.erase(v_my.begin() + 1000);
        v_std.erase(v_std.begin() + 1000);
        my_output << v_my.size();
        std_output << v_std.size();
        v_my.erase(v_my.begin() + 2000);
        v_std.erase(v_std.begin() + 2000);
        my_output << v_my.size();
        std_output << v_std.size();
    }
    {
        std::cout << "Test erase with first and last position..." << std::endl;

        size_t n = 5000;
        ft::vector<int> v_my(n, 999999);
        std::vector<int> v_std(n, 999999);
        ft::vector<int>::iterator first_my = v_my.begin();
        std::vector<int>::iterator first_std = v_std.begin();
        my_output << v_my.size();
        std_output << v_std.size();
        v_my.erase(first_my, v_my.end());
        v_std.erase(first_std, v_std.end());
        my_output << v_my.size();
        std_output << v_std.size();

        my_output << v_my.empty();
        std_output << v_std.empty();
    }
    my_output.close();
    std_output.close();
    check_diff();
}

void test_swap() {
    std::ofstream my_output;
    std::ofstream std_output;

    my_output.open(MY_OUTPUT);
    std_output.open(STD_OUTPUT);
    std::cout << "Test swap()" << std::endl;
    {
        size_t n = 5000;
        ft::vector<int> v_my;
        std::vector<int> v_std;
        ft::vector<int> v_2_my(n, 999999);
        std::vector<int> v_2_std(n, 999999);
        my_output << v_my.size();
        std_output << v_std.size();
        my_output << v_2_my.size();
        std_output << v_2_std.size();
        v_my.swap(v_2_my);
        v_std.swap(v_2_std);
        my_output << v_my.size();
        std_output << v_std.size();
        my_output << v_2_my.size();
        std_output << v_2_std.size();
        v_my.swap(v_2_my);
        v_std.swap(v_2_std);
        my_output << v_my.size();
        std_output << v_std.size();
        my_output << v_2_my.size();
        std_output << v_2_std.size();
    }
    {
        size_t n = 5000;
        ft::vector<int> v_my(n, 11);
        std::vector<int> v_std(n, 11);
        ft::vector<int> v_2_my(n/2, 999999);
        std::vector<int> v_2_std(n/2, 999999);
        my_output << v_my.size();
        std_output << v_std.size();
        my_output << v_2_my.size();
        std_output << v_2_std.size();
        v_my.swap(v_2_my);
        v_std.swap(v_2_std);
        my_output << v_my.size();
        std_output << v_std.size();
        my_output << v_2_my.size();
        std_output << v_2_std.size();
        v_my.swap(v_2_my);
        v_std.swap(v_2_std);
        my_output << v_my.size();
        std_output << v_std.size();
        my_output << v_2_my.size();
        std_output << v_2_std.size();
    }
    my_output.close();
    std_output.close();
    check_diff();
}

void test_clear() {
    std::ofstream my_output;
    std::ofstream std_output;

    my_output.open(MY_OUTPUT);
    std_output.open(STD_OUTPUT);
    std::cout << "Test clear()" << std::endl;
    {
        size_t n = 5000;
        ft::vector<int> v_my;
        std::vector<int> v_std;
        ft::vector<int> v_2_my(n, 999999);
        std::vector<int> v_2_std(n, 999999);
        my_output << v_my.size();
        std_output << v_std.size();
        my_output << v_2_my.size();
        std_output << v_2_std.size();
        v_my.clear();
        v_std.clear();
        v_2_my.clear();
        v_2_std.clear();
        my_output << v_my.size();
        std_output << v_std.size();
        my_output << v_2_my.size();
        std_output << v_2_std.size();
    }
    my_output.close();
    std_output.close();
    check_diff();
}

void make_vector_test() {
    std::cout << MAGENTA << "-------------------------------" << std::endl;
    std::cout << "     VECTOR TESTER STARTED" << std::endl;
    std::cout << "-------------------------------" << RESET << std::endl;

    test_constructor();
    test_emty();
    test_operator();
    test_at();
    test_front();
    test_back();
    test_assign();
    test_push_back();
    test_pop_back();
    test_insert();
    test_erase();
    test_swap();
    test_clear();
}

