#pragma once
#include "Resources/GLEW/include/GL/glew.h"
#include "VertexAttribute.hpp"
#include "VertexBuffer.hpp"
#include "opengl_types.hpp"

class VertexArray{
private:
    unsigned int m_RenderID;

public:
    VertexArray();
    ~VertexArray();

    void bind() const;
    void unBind() const;

    void addBufferAndAttribute(const void* vertexBufferData, unsigned int dataSize, const VertexAttribute& vertexAttribute) const;
};