cmake_minimum_required(VERSION 3.20)
project(Casse_briques_3MOC)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Casse_briques_3MOC main.c method/map.c)
