
#include "VertexBuffer.hpp"
#include "error_handle.hpp"

VertexBuffer::VertexBuffer(const void* vertexBufferData, unsigned int dataSize) : m_VrtexBufferData(vertexBufferData), m_DataSize(dataSize), m_RenderID(0) {
    GLCALL(glGenBuffers(1, &m_RenderID));
    GLCALL(glBindBuffer(GL_ARRAY_BUFFER, m_RenderID));
    GLCALL(glBufferData(GL_ARRAY_BUFFER, m_DataSize, m_VrtexBufferData, GL_STREAM_DRAW));
    GLCALL(glBindBuffer(GL_ARRAY_BUFFER, 0));
}

void VertexBuffer::bind() const {
    GLCALL(glBindBuffer(GL_ARRAY_BUFFER, m_RenderID));
}

void VertexBuffer::unBind() const{
    GLCALL(glBindBuffer(GL_ARRAY_BUFFER, 0));
}

VertexBuffer::~VertexBuffer(){
    GLCALL(glDeleteBuffers(1, &m_RenderID));
}