cmake_minimum_required(VERSION 3.9)
project(c_sorts)
set(CMAKE_CXX_STANDARD 11)

add_library(c_sorts SHARED c_sorts.c c_sorts.h)