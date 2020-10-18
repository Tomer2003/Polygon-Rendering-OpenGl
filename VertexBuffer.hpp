#pragma once
#include "Resources/GLEW/include/GL/glew.h"

class VertexBuffer{
private:
    unsigned int m_RenderID;
    unsigned int m_DataSize;
    float* m_VrtexBufferData;

public:
    VertexBuffer(float* vertexBufferData, unsigned int dataSize);
    ~VertexBuffer();

    void bind() const;
    void unBind() const;
};