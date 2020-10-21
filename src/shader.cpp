#include "shader.hpp"
#include "files_io.hpp"

unsigned int Shader::getCompiledShader(const std::string& shaderSource, GLenum shaderType) const{
    unsigned int shader = glCreateShader(shaderType);
    const char* shaderSourcePtr = shaderSource.c_str();
    glShaderSource(shader, 1, &shaderSourcePtr, nullptr);
    glCompileShader(shader);

    return shader;
}

Shader::Shader(const std::string& vertexShaderFileSource, const std::string& fragmentShaderFileSource){
    this->m_RenderID = glCreateProgram();
    
    unsigned int vertexShader = getCompiledShader(getDataFile(vertexShaderFileSource), GL_VERTEX_SHADER);
    unsigned int fragmentShader =  getCompiledShader(getDataFile(fragmentShaderFileSource), GL_FRAGMENT_SHADER);

    glAttachShader(m_RenderID, vertexShader);
    glAttachShader(m_RenderID, fragmentShader);

    glLinkProgram(m_RenderID);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
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

int Shader::getUniformID(const std::string& uniformName) const{
    return glGetUniformLocation(m_RenderID, uniformName.c_str());
}

void Shader::setUniform4f(const std::string& uniformName, float v1, float v2, float v3, float v4) const{
    glUniform4f(this->getUniformID(uniformName), v1, v2, v3, v4);
}