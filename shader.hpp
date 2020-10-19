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

    void setUniform4f(const std::string& uniformName, float v1, float v2, float v3, float v4) const;
private:
    unsigned int getCompiledShader(const std::string& shaderSource, GLenum shaderType) const;
    int getUniformID(const std::string& uniformName) const;
};