#include "shader.hpp"


unsigned int Shader::getCompiledShader(const std::string& shaderSource, GLenum shaderType) const{
    unsigned int shader = glCreateShader(shaderType);
    const char* shaderSourcePtr = shaderSource.c_str();
    glShaderSource(shader, 1, &shaderSourcePtr, nullptr);
    
    glCompileShader(shader);
    return shader;
}

Shader::Shader(const std::string& vertexShaderSource, const std::string& fragmentShaderSource){
    this->m_RenderID = glCreateProgram();

    unsigned int vertexShader = getCompiledShader(vertexShaderSource, GL_VERTEX_SHADER);
    unsigned int fragmentShader =  getCompiledShader(vertexShaderSource, GL_FRAGMENT_SHADER);

    glAttachShader(m_RenderID, vertexShader);
    glAttachShader(m_RenderID, fragmentShader);

    glLinkProgram(m_RenderID);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    glDeleteProgram(0);
}

Shader::~Shader(){
    glDeleteProgram(m_RenderID);
}

void Shader::bind() const{
    glUseProgram(m_RenderID);
}

void Shader::unBind() const{
    glUseProgram(0);
}