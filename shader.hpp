#pragma once
#include "Resources/GLEW/include/GL/glew.h"
#include <string>

class Shader{
private:
    unsigned int m_RenderID;

public:
    Shader(const std::string& vertexShaderSource, const std::string& fragmentShaderSource);
    ~Shader();

    void bind() const;
    void unBind() const;

private:
    unsigned int getCompiledShader(const std::string& shaderSource, GLenum shaderType) const;
};