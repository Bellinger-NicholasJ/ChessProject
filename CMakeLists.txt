# Set the minimum required CMake version.
cmake_minimum_required(VERSION 3.16)

# Define the chess project.
project(chess VERSION 1.0 LANGUAGES CXX)

# Set C++ standard.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source files.
add_executable(chess 
    src/main.cpp
)

# Include directories.
target_include_directories(chess PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Precompiled headers.
target_precompile_headers(chess PRIVATE 
    "include/pch.hpp"
)