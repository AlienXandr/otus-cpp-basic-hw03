cmake_minimum_required(VERSION 3.5)

project(datetime)

add_library(datetime SHARED
        datetime.cpp
        datetime.h
)

set_target_properties(datetime PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)