cmake_minimum_required(VERSION 3.30)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled main.cpp
        include/controllers/Sistema.h
        include/models/Vuelo.h
        include/models/Usuario.h
        include/models/Reservacion.h
        include/models/Avion.h
        include/controllers/ManejadorAvion.h
        include/controllers/ManejadorUsuario.h
        include/controllers/ManejadorVuelo.h
        include/controllers/ManejadorReserva.h
)
