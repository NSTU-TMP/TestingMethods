cmake_minimum_required(VERSION 3.10)

project(PolishNotation LANGUAGES C)


add_library(polish_notation STATIC 
    stack.c
    stack.h
    polish_notation.c
    polish_notation.h
    parsing.c
    parsing.h
)
