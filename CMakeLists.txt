cmake_minimum_required(VERSION 3.20)   # Versión mínina
project(breakB)                         # Nombre del proyecto

include_directories(include)           # Incluir la carpeta de headers

set(SOURCES
    main.cpp
    src/ball.cpp
    src/paddle.cpp
    src/brick.cpp
)

add_executable(breakB ${SOURCES})       # Crear el ejecutable con los archivos fuente
target_link_libraries(breakB raylib)    # Enlazar la biblioteca raylib

