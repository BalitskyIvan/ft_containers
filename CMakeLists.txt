cmake_minimum_required(VERSION 3.17)
project(containers)

set(CMAKE_CXX_STANDARD 98)

include_directories(containers testers)
add_compile_options(-Wall -Wextra -Werror -Wconversion -Wno-unused)

add_executable(containers main.cpp Entity/Entity.cpp Entity/Entity.hpp
        containers/Map.hpp containers/Vector.hpp containers/Stack.hpp containers/reimplemented_staff.hpp)