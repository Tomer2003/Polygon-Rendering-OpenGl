#include "shader.hpp"
#include "error_handle.hpp"
#include "files_io.hpp"

unsigned int Shader::getCompiledShader(const std::string& shaderSource, GLenum shaderType) const{
    GLCALL(unsigned int shader = glCreateShader(shaderType));
    const char* shaderSourcePtr = shaderSource.c_str();
    GLCALL(glShaderSource(shader, 1, &shaderSourcePtr, nullptr));
    GLCALL(glCompileShader(shader));

    return shader;
}

Shader::Shader(const std::string& vertexShaderFileSource, const std::string& fragmentShaderFileSource){
    GLCALL(this->m_RenderID = glCreateProgram());
    
    unsigned int vertexShader = getCompiledShader(getDataFile(vertexShaderFileSource), GL_VERTEX_SHADER);
    unsigned int fragmentShader =  getCompiledShader(getDataFile(fragmentShaderFileSource), GL_FRAGMENT_SHADER);

    GLCALL(glAttachShader(m_RenderID, vertexShader));
    GLCALL(glAttachShader(m_RenderID, fragmentShader));

    GLCALL(glLinkProgram(m_RenderID));

    GLCALL(glDeleteShader(vertexShader));
    GLCALL(glDeleteShader(fragmentShader));
}

Shader::~Shader(){
    GLCALL(glDeleteProgram(m_RenderID));
}

void Shader::bind() const{
    GLCALL(glUseProgram(m_RenderID));
}

void Shader::unBind() const{
    GLCALL(glUseProgram(0));
}

int Shader::getUniformID(const std::string& uniformName) const{
    GLCALL(return glGetUniformLocation(m_RenderID, uniformName.c_str()));
}

void Shader::setUniform4f(const std::string& uniformName, float v1, float v2, float v3, float v4) const{
    GLCALL(glUniform4f(this->getUniformID(uniformName), v1, v2, v3, v4));
}