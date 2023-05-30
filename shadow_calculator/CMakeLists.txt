cmake_minimum_required(VERSION 3.10)

project(ShadowCalculator LANGUAGES C)


add_library(shadow_calculator STATIC 
    calc_shadow_length.c 
    segment.h
)
