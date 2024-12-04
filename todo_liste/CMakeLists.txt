cmake_minimum_required(VERSION 3.29)
project(todo_liste C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(todo_liste
    main.c
    malib.c
    malib.h)
