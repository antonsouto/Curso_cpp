# Establece la versión mínima de CMake requerida
cmake_minimum_required(VERSION 3.10)

# Establece el nombre del proyecto
project(SmartPointersProject)

# Establece el estándar de C++ a utilizar
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Agrega el ejecutable
add_executable(SmartPointersExecutable smartpointers.cpp)

# Especifica las bibliotecas que se necesitan (en este caso no hay ninguna adicional)
# target_link_libraries(SmartPointersExecutable <libraries>)
