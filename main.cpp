#include <iostream>
#include <string>
#include <deque>
#include "Vector.hpp"

#include <stdlib.h>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096

#include "containers/Map.hpp"
struct Buffer
{
  int idx;
  char buff[BUFFER_SIZE];
};


#define COUNT (MAX_RAM / (int)sizeof(Buffer))

//template<typename T>
//class MutantStack : public ft::stack<T>
//{
//public:
//  MutantStack() {}
//  MutantStack(const MutantStack<T>& src) { *this = src; }
//  MutantStack<T>& operator=(const MutantStack<T>& rhs)
//  {
//    this->c = rhs.c;
//    return *this;
//  }
//  ~MutantStack() {}
//
//  typedef typename ft::stack<T>::container_type::iterator iterator;
//
//  iterator begin() { return this->c.begin(); }
//  iterator end() { return this->c.end(); }
//};

int main(int argc, char** argv) {
//  if (argc != 2)
//  {
//    std::cerr << "Usage: ./test seed" << std::endl;
//    std::cerr << "Provide a seed please" << std::endl;
//    std::cerr << "Count value:" << COUNT << std::endl;
//    return 1;
//  }
//  const int seed = atoi(argv[1]);
//  srand(seed);
//  ft::map<int, std::string> map;
//  ft::vector<std::string> vector_str;
//  ft::vector<int> vector_int;
//  ft::vector<Buffer> vector_buffer;

//  for (int i = 0; i < COUNT; i++)
//  {
//    vector_buffer.push_back(Buffer());
//  }
//
//  for (int i = 0; i < COUNT; i++)
//  {
//    const int idx = rand() % COUNT;
//    vector_buffer[idx].idx = 5;
//  }
//  ft::vector<Buffer>().swap(vector_buffer);
//
//  try
//  {
//    for (int i = 0; i < COUNT; i++)
//    {
//      const int idx = rand() % COUNT;
//      vector_buffer.at(idx);
//      std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
//    }
//  }
//  catch(const std::exception& e)
//  {
//    std::cout << "NORM" << std::endl;
//  }
//  std::map<int, std::string> mp1;
//  mp1.insert(std::pair<int, std::string>(8, "1"));
//  mp1.insert(std::pair<int, std::string>(2, "2"));
//  mp1.insert(std::pair<int, std::string>(3, "3"));
//  mp1.insert(std::pair<int, std::string>(4, "4"));
//  mp1.insert(std::pair<int, std::string>(5, "1"));
//  mp1.insert(std::pair<int, std::string>(6, "2"));
//  mp1.insert(std::pair<int, std::string>(7, "3"));
//  mp1.insert(std::pair<int, std::string>(1, "4"));
//
//  std::map<int, std::string>::iterator first = mp1.begin();
//  std::map<int, std::string>::iterator last = mp1.end();

//  while (first != last) {
//    std::cout << first->second << std::endl;
//    first++;
//  }

  ft::vector<int> a1;




  return (0);
}