# Set the minimum required CMake version.
cmake_minimum_required(VERSION 3.16)

# Define the glad project.
project(glad LANGUAGES C)

# Set the C standard.
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Source files.
add_library(glad STATIC
    src/glad.c
)

#include directories.
target_include_directories(glad PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)