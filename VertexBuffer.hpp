#pragma once
#include "Resources/GLEW/include/GL/glew.h"

class VertexBuffer{
private:
    unsigned int m_RenderID;
    unsigned int m_DataSize;
    const void* m_VrtexBufferData;

public:
    /**
     * @brief Construct a new Vertex Buffer object
     * 
     * @param vertexBufferData - pointer to array of vertexes data
     * @param dataSize - size of array
     */
    VertexBuffer(const void* vertexBufferData, unsigned int dataSize);
    /**
     * @brief Destroy the Vertex Buffer object
     * 
     */
    ~VertexBuffer();

    /**
     * @brief The function bind the vertex buffer
     * 
     */
    void bind() const;
    /**
     * @brief The function unbind the vertex buffer
     * 
     */
    void unBind() const;
};