cmake_minimum_required(VERSION 3.20)
project(clion_get_next_line C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(clion_get_next_line
        get_next_line.c
        get_next_line.h
        get_next_line_utils.c
        main.c)
