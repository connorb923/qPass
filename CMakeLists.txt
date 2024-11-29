cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 23)

project ("qPass")

add_executable (qPass
    "src/main.cpp"
    "include/main.h"
)