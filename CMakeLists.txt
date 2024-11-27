cmake_minimum_required(VERSION 3.30)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled main.cpp
        include/Sistema.h
        include/Vuelo.h
        include/Usuario.h
        include/Reservacion.h
        ../Aeropuerto/include/test.h
        src/Sistema.cpp
        include/Sistema.cpp
)
