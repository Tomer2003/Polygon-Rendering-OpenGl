#pragma once
#include "Resources/GLEW/include/GL/glew.h"

class VertexBuffer{
private:
    unsigned int m_RenderID;
    unsigned int m_DataSize;
    const void* m_VrtexBufferData;

public:
    VertexBuffer(const void* vertexBufferData, unsigned int dataSize);
    ~VertexBuffer();

    void bind() const;
    void unBind() const;
};