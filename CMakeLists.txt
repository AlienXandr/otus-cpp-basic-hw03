cmake_minimum_required(VERSION 3.5)

project(03.guess_number)

add_subdirectory(lib/static/clear_cin)
add_subdirectory(lib/dynamic/datetime)

add_executable(guess_number
        main.cpp
        src/argument_parse/argument_parse.cpp
        src/argument_parse/argument_parse.h
        src/get_random_value/get_random_value.cpp
        src/get_random_value/get_random_value.h
        src/check_value/check_value.cpp
        src/check_value/check_value.h
        src/get_user_name/get_user_name.cpp
        src/get_user_name/get_user_name.h
        src/result_table/save_result.cpp
        src/result_table/save_result.h
        src/result_table/print_res_table.cpp
        src/result_table/print_res_table.h
)

target_link_libraries(guess_number
        PUBLIC clear_cin
        PUBLIC datetime
)

set_target_properties(guess_number PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)