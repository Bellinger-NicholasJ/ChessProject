/* Copyright (c) 2025 Nicholas Bellinger
Licensed under the Chess 1.5 Non-Commercial License v1.0.
See the LICENSE file in the project root for full terms. */

#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "Sprite.hpp"

struct GLFWwindow;

class Window {
    public:
        static float DeltaTime;
        static int Height;
        static int Width;
    
        static void Clear(void);
        static bool CreateWindow(int width = Width, int height = Height, const char* title = "Chess 1.5");
        static void DestroyWindow(void);
        static void Draw(std::vector<Sprite>& sprites);
        static bool IsClosed(void);
        static void Update(void);
        static void Render(void);

    private:
        static GLFWwindow* m_window;

        static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
};

#endif