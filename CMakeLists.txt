cmake_minimum_required(VERSION 3.26)
project(cple C)

set(CMAKE_C_STANDARD 23)

add_executable(cple main.c
        ch1/ch1.h
        ch1/1_19.h)
