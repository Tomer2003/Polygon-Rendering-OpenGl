#pragma once
#include "Resources/GLEW/include/GL/glew.h"

class IndexBuffer{
private:
    unsigned int m_RenderID;
    unsigned int m_size;

public:
    /**
     * @brief Construct a new Index Buffer object
     * 
     * @param buffer - pointer to index buffer data array
     * @param bufferSize - size fo index buffer data array
     */
    IndexBuffer(const void* buffer, unsigned int bufferSize);
    /**
     * @brief Destroy the Index Buffer object
     * 
     */
    ~IndexBuffer();

    /**
     * @brief The function bind index buffer
     * 
     */
    void bind() const;
    /**
     * @brief The function un bind index buffer
     * 
     */
    void unBind() const;

    /**
     * @brief The function return index buffer size 
     * 
     * @return unsigned int - index buffer size
     */
    unsigned int getBufferSize() const;
};