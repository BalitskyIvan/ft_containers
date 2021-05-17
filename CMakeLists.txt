cmake_minimum_required(VERSION 3.17)
project(containers)

set(CMAKE_CXX_STANDARD 98)

add_executable(containers main.cpp Entity/Entity.cpp Entity/Entity.hpp)