cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(VectorProcessing)

# Establecer el estándar de C++ a utilizar
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Añadir el archivo fuente
add_executable(VectorProcessing main.cpp)
