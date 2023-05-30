cmake_minimum_required(VERSION 3.10)

project(SrcModule LANGUAGES C)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(Executable.out main.c)


target_include_directories(
    Executable.out
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../shadow_calculator_tests
)

target_link_directories(
    Executable.out   
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../shadow_calculator_tests
)

target_include_directories(
    Executable.out
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../polish_notation_tests
)

target_link_directories(
    Executable.out   
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../polish_notation_tests
)

target_link_libraries(Executable.out 
    shadow_calculator_tests 
    polish_notation_tests
)
