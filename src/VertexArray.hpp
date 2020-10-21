#pragma once
#include "../Resources/GLEW/include/GL/glew.h"
#include "VertexAttribute.hpp"
#include "VertexBuffer.hpp"
#include "opengl_types.hpp"

class VertexArray{
private:
    unsigned int m_RenderID;

public:
    /**
     * @brief Construct a new Vertex Array object
     * 
     */
    VertexArray();
    /**
     * @brief Destroy the Vertex Array object
     * 
     */
    ~VertexArray();

    /**
     * @brief The function bind vertex array object
     * 
     */
    void bind() const;
    /**
     * @brief The function un bind vertex array object
     * 
     */
    void unBind() const;

    /**
     * @brief The function bind vertex buffer and vertex attribute to vertex array
     * 
     * @param vertexBuffer - vertex buffer object to bind
     * @param vertexAttribute - vertex attribute object to bind
     */
    void addBufferAndAttribute(const VertexBuffer& vertexBuffer, const VertexAttribute& vertexAttribute) const;
};