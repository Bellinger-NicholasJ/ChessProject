/* Copyright (c) 2025 Nicholas Bellinger
Licensed under the Chess 1.5 Non-Commercial License v1.0.
See the LICENSE file in the project root for full terms. */

#include "pch.hpp"
#include "Window.hpp"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

/// @brief Entry point of the program
/// @retval 0 on successful execution
/// @retval non-zero on error
int main(void) {
    if (!Window::CreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Chess 1.5")) {
        return -1;
    }

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    std::vector<Sprite> sprites;
    Shader *spriteShader = new Shader("../assets/shaders/vertexShader.glsl", "../assets/shaders/fragmentShader.glsl");
    Texture *whitePawnTexture = new Texture("../assets/textures/pixelChessPieces/whitePawn.png");
    Sprite whitePawn(spriteShader, whitePawnTexture);
    sprites.push_back(whitePawn);

    // Main loop.
    while (!Window::IsClosed()) {
        // Render here.
        Window::Clear();

        Window::Draw(sprites);

        Window::Render();

        Window::Update();
    }

    // Cleanup and exit.
    for (size_t i = 0; i < sprites.size(); i++) {
        sprites.pop_back();
    }
    Window::DestroyWindow();

    return 0;
}