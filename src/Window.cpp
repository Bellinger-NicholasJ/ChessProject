/* Copyright (c) 2025 Nicholas Bellinger
Licensed under the Chess 1.5 Non-Commercial License v1.0.
See the LICENSE file in the project root for full terms. */

#include "pch.hpp"
#include "Window.hpp"

void Window::Clear(void) {
    glClear(GL_COLOR_BUFFER_BIT);
}

bool Window::CreateWindow(int width, int height, const char* title) {
    // Initialize the GLFW library.
    if (!glfwInit()) {
        std::cerr << "ERROR::GLFW::FAILED_TO_INITIALIZE\n";
        return false;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif

    // Create a windowed mode window and its OpenGL context.
    m_window = glfwCreateWindow(width, height, "Chess 1.5", nullptr, nullptr);
    if (!m_window) {
        std::cerr << "ERROR::GLFW::FAILED_TO_CREATE_WINDOW\n";
        glfwTerminate();
        return false;
    }

    // Make the window's context current.
    glfwMakeContextCurrent(m_window);

    // Load OpenGL function pointers using GLAD.
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "ERROR::GLAD::FAILED_TO_INITIALIZE\n";
        glfwTerminate();
        return -1;
    }

    // Initialize window settings.
    glfwSetFramebufferSizeCallback(m_window, Window::framebuffer_size_callback);
    glClearColor(0.0f, (200.0f / 255.0f), 1.0f, 1.0f);
    stbi_set_flip_vertically_on_load(true);

    return true;
}

void Window::DestroyWindow(void) {
    glfwDestroyWindow(m_window);
    glfwTerminate();
}

void Window::Draw(std::vector<Sprite>& sprites) {
    for (int i = 0; i < sprites.size(); ++i) {
        // Draw each sprite in the array.
        sprites[i].Draw();
    }
}

bool Window::IsClosed(void) {
    return glfwWindowShouldClose(m_window);
}

void Window::Render(void) {
    // Swap front and back buffers.
    glfwSwapBuffers(m_window);
}

void Window::Update(void) {
    // Poll for and process events.
    glfwPollEvents();
}

void Window::framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
    Window::Width = width;
    Window::Height = height;
}

float Window::DeltaTime = 0.0f;
int Window::Height = 600;
int Window::Width = 800;
GLFWwindow* Window::m_window = nullptr;