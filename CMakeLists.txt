cmake_minimum_required(VERSION 3.24)
project(stack)

set(CMAKE_CXX_STANDARD 17)

add_executable(stack main.cpp MyStack.cpp MyStack.h)
add_subdirectory(tests)