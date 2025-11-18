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
    src/Shader.cpp
    src/Sprite.cpp
    src/Texture.cpp
    src/Window.cpp
)

# Disable OpenGL deprecation warnings on macOS.
if (APPLE)
    target_compile_definitions(chess PRIVATE GL_SILENCE_DEPRECATION)
endif()

# Include directories.
target_include_directories(chess PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Build vendored dependencies.
add_subdirectory(vendors/glad)
add_subdirectory(vendors/glfw)
add_subdirectory(vendors/glm)
add_subdirectory(vendors/stb)

# Link vendored libraries.
target_link_libraries(chess PRIVATE 
    glfw
    glad
    glm
    stb
)

# Precompiled headers.
target_precompile_headers(chess PRIVATE 
    "include/pch.hpp"
)