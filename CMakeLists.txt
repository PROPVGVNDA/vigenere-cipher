cmake_minimum_required(VERSION 3.16)
project(vigenere)

set(CMAKE_CXX_STANDARD 17)

add_executable(vigenere main.cpp functions.cpp functions.h)