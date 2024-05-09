cmake_minimum_required(VERSION 3.5)

project(clear_cin)

add_library(clear_cin STATIC
        clear_cin.cpp
        clear_cin.h
)

set_target_properties(clear_cin PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)