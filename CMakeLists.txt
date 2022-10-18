cmake_minimum_required(VERSION 3.23)
project(Casse_briques_3MOC C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Casse_briques_3MOC main.c
        header/header.h method/method.c)
