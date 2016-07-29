cmake_minimum_required(VERSION 3.5)
project(Data_Structure)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    .gitattributes
    .gitignore C++/Tree/tree.h C++/Tree/test.cpp)

add_executable(Data_Structure ${SOURCE_FILES})