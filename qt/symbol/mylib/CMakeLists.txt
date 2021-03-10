cmake_minimum_required(VERSION 3.12)

project(symbol)

add_library(mylib_b SHARED
    mylib_b.cc
)

add_library(mylib_a SHARED
    mylib_a.cc
)

target_link_libraries(mylib_a
    mylib_b
)
