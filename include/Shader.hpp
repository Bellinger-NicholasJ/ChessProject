#ifndef SHADER_HPP
#define SHADER_HPP

#include <string>

class Shader {
    public:
        unsigned int ID;

        Shader(const char* vertexPath, const char* fragmentPath);

        void Use(void);

    private:
        void createProgram(unsigned int vertexShader, unsigned int fragmentShader);
        unsigned int createShader(const char* shaderSource, int shaderType);
        std::string readFile(const char* filePath);
};

#endif