#include "Entity/Entity.hpp"
#include "containers/List.hpp"
#include "containers/Vector.hpp"
#include <list>
#include <iostream>
#include <cmath>
#include <vector>

int main() {
  {
    std::vector<int> myvector;
    int myint;

    for (int i = 0; i < 11; i++)
      myvector.push_back(i);

    std::vector<int>::iterator first = myvector.begin();
    while (first != myvector.end()) {
      std::cout << *first;
      first++;
    }
    std::cout << std::endl;
    std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n"
              << std::endl;
  }
  {
    ft::vector<int> myvector;
    int  myint = 3;

    for (int i = 0; i < myint; i++)
      myvector.push_back (i);
    ft::vector<int>::iterator first = myvector.begin();
    ft::vector<int>::iterator last = myvector.end();

    std::cout << "first is " << *first << " last is " << *(--last) <<
        " size is " << std::endl;
    while (first != last) {
      std::cout << *first;
      first++;
    }
    std::cout << std::endl;
    std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n"
              << std::endl;
  }
}

