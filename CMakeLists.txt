cmake_minimum_required(VERSION 3.10)

project(main LANGUAGES CXX)


if (DEBUG)
    add_compile_options(-Wall -Werror -Wextra)
    add_compile_options(-g3 -ggdb -g)
endif()


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(shadow_calculator)
include_directories(shadow_calculator)

add_subdirectory(shadow_calculator_tests)
include_directories(shadow_calculator_tests)

add_subdirectory(polish_notation)
include_directories(polish_notation)

add_subdirectory(polish_notation_tests)
include_directories(polish_notation_tests)

add_subdirectory(src)