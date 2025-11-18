/* Copyright (c) 2025 Nicholas Bellinger
Licensed under the Chess 1.5 Non-Commercial License v1.0.
See the LICENSE file in the project root for full terms. */

#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "Shader.hpp"
#include "Texture.hpp"

class Sprite {
    public:
        Sprite(Shader* shader, Texture* texture);
        ~Sprite(void);

        void Draw(void);

    private:
        glm::vec2 m_position;
        glm::vec2 m_rotation;
        glm::vec2 m_scale;
        Shader *m_shader;
        Texture *m_texture;

        unsigned int m_vao;
        unsigned int m_vbo;
        unsigned int m_ebo;
};

#endif