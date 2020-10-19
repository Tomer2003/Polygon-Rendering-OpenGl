#pragma once
#include "Resources/GLEW/include/GL/glew.h"

class IndexBuffer{
private:
    unsigned int m_RenderID;
    unsigned int m_size;

public:
    IndexBuffer(const void* buffer, unsigned int bufferSize);
    ~IndexBuffer();

    void bind() const;
    void unBind() const;

    unsigned int getBufferSize() const;
};