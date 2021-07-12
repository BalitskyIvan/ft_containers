cmake_minimum_required(VERSION 3.17)
project(containers)

set(CMAKE_CXX_STANDARD 98)
add_subdirectory(tests_stl tests_stl/lib)

include_directories(containers)

add_executable(containers main.cpp Entity/Entity.cpp Entity/Entity.hpp
        containers/Map.hpp containers/Vector.hpp containers/Stack.hpp testers/vector_test.cpp testers/map_test.cpp testers/stack_tester.cpp)