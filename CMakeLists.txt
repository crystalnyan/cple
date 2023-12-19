cmake_minimum_required(VERSION 3.26)
project(cple C)

set(CMAKE_C_STANDARD 23)

add_executable(cple main.c
        ch1/ch1.h
        ch1/1_16.c
        ch1/1_17.c
        ch1/1_18.c
        ch1/1_19.c
        ch1/1_20.c
        ch1/1_21.c
        ch1/1_22.c
)
