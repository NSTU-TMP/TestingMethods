cmake_minimum_required(VERSION 3.10)

project(ShadowCalculatorTests LANGUAGES C)


add_library(shadow_calculator_tests STATIC 
    shadow_calculator_tests.c
    shadow_calculator_tests.h
    tests.c
)


target_include_directories(
    shadow_calculator_tests
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../shadow_calculator
)

target_link_directories(
    shadow_calculator_tests
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../shadow_calculator
)

target_link_libraries(shadow_calculator_tests shadow_calculator)
