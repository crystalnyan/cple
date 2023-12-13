cmake_minimum_required(VERSION 3.26)
project(chipotle C)

set(CMAKE_C_STANDARD 23)

add_executable(chipotle main.c
        ch1/ch1.h
        ch1/1_16.c
        ch1/1_17.c
        ch1/1_18.c
        ch1/1_19.c
)
