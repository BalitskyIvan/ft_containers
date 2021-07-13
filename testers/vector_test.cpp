//
// Created by Lonmouth Mallador on 7/12/21.
//

#include <fstream>
#include <iostream>

void test_constructor(std::ofstream file) {

}

void make_vector_test() {
  std::cout << "-------------------------------" << std::endl;
  std::cout << "     VECTOR TESTER STARTED" << std::endl;
  std::cout << "-------------------------------" << std::endl;

  std::ofstream test_file;
  test_file.open("test_file.txt");
  test_constructor(test_file);
  std::remove("test_file.txt");
  test_file.open("test_file.txt");

}

