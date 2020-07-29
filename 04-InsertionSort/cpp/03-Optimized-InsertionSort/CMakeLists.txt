# cmake_minimum_required(VERSION <specify CMake version here>)
project(InsertionSort)

set(CMAKE_CXX_STANDARD 17)

add_executable(InsertionSort main.cc ArrayGenerator.h SortingHelper.h)