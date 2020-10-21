#pragma once
#include "Resources/GLEW/include/GL/glew.h"
#include <string>

class Shader{
private:
    unsigned int m_RenderID;

public:
    /**
     * @brief Construct a new Shader object
     * 
     * @param vertexShaderFileSource - vertex shader source file name
     * @param fragmentShaderFileSource  - fragment shader source file name
     */
    Shader(const std::string& vertexShaderFileSource, const std::string& fragmentShaderFileSource);
    /**
     * @brief Destroy the Shader object
     * 
     */
    ~Shader();

    /**
     * @brief The function bind shader object
     * 
     */
    void bind() const;
    /**
     * @brief The function un bind shader object
     * 
     */
    void unBind() const;

    /**
     * @brief Set the Uniform4f object for shader
     * 
     * @param uniformName - uniform name
     * @param v1 - R
     * @param v2 - G
     * @param v3 - B
     * @param v4 - A
     */
    void setUniform4f(const std::string& uniformName, float v1, float v2, float v3, float v4) const;
private:
    /**
     * @brief Get the Compiled Shader object
     * 
     * @param shaderSource - shader source data
     * @param shaderType - shader type
     * @return unsigned int - shader ID
     */
    unsigned int getCompiledShader(const std::string& shaderSource, GLenum shaderType) const;
    /**
     * @brief The function return uniform ID
     * 
     * @param uniformName - uniform name
     * @return int - uniform ID
     */
    int getUniformID(const std::string& uniformName) const;
};