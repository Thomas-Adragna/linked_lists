cmake_minimum_required(VERSION 3.29)
project(Messages_de_log C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Messages_de_log
    lib_log.c
    lib_log.h
    main.c
        tests.c
        tests.h)
