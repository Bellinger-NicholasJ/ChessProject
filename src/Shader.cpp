

#include "pch.hpp"
#include "Shader.hpp"

Shader::Shader(const char* vertexPath, const char* fragmentPath) {
    std::string vertexSource = readFile(vertexPath);
    unsigned int vertexShader = createShader(vertexSource.c_str(), GL_VERTEX_SHADER);

    std::string fragmentSource = readFile(fragmentPath);
    unsigned int fragmentShader = createShader(fragmentSource.c_str(), GL_FRAGMENT_SHADER);

    createProgram(vertexShader, fragmentShader);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void Shader::Use(void) {
    glUseProgram(this->ID);
}

void Shader::createProgram(unsigned int vertexShader, unsigned int fragmentShader) {
    this->ID = glCreateProgram();
    glAttachShader(this->ID, vertexShader);
    glAttachShader(this->ID, fragmentShader);
    glLinkProgram(this->ID);

    int success;
    char infoLog[512];
    glGetProgramiv(this->ID, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(this->ID, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
}

unsigned int Shader::createShader(const char* shaderSource, int shaderType) {
    unsigned int shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, &shaderSource, nullptr);
    glCompileShader(shader);

    int success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        std::cout << "ERROR::SHADER::" << (shaderType == GL_VERTEX_SHADER ? "VERTEX_SHADER" : "FRAGMENT_SHADER") << "::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    return shader;
}

std::string Shader::readFile(const char* filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "ERROR::SHADER::FAILED_TO_OPEN::" << filePath << std::endl;
        return "";
    }

    std::stringstream buff;
    buff << file.rdbuf();

    file.close();

    return buff.str();
}