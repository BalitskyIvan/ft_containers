cmake_minimum_required(VERSION 3.17)
project(containers)

set(CMAKE_CXX_STANDARD 98)

include_directories(containers testers)

add_executable(containers testers main.cpp Entity/Entity.cpp Entity/Entity.hpp
        containers/Map.hpp containers/Vector.hpp containers/Stack.hpp containers/reimplemented_staff.hpp)