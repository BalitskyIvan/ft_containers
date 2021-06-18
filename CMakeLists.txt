cmake_minimum_required(VERSION 3.17)
project(containers)

set(CMAKE_CXX_STANDARD 98)
add_subdirectory(tests_stl tests_stl/lib)

add_executable(containers main.cpp Entity/Entity.cpp Entity/Entity.hpp containers/Stack.hpp containers/Queue.hpp
        containers/Map.hpp containers/Vector.hpp)