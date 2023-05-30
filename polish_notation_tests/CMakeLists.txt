cmake_minimum_required(VERSION 3.10)

project(PolishNotationTests LANGUAGES C)


add_library(polish_notation_tests STATIC 
    polish_notation_tests.c 
    polish_notation_tests.h 
    tests.c
)


target_include_directories(
    polish_notation_tests
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../polish_notation
)

target_link_directories(
    polish_notation_tests
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../polish_notation
)

target_link_libraries(polish_notation_tests polish_notation)
