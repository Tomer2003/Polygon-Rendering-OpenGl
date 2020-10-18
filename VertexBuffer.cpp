
#include "VertexBuffer.hpp"

VertexBuffer::VertexBuffer(const void* vertexBufferData, unsigned int dataSize) : m_VrtexBufferData(vertexBufferData), m_DataSize(dataSize), m_RenderID(0) {
    glGenBuffers(1, &m_RenderID);
    glBindBuffer(GL_ARRAY_BUFFER, m_RenderID);
    glBufferData(GL_ARRAY_BUFFER, m_DataSize, m_VrtexBufferData, GL_STREAM_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    //free(vertexBufferData); or unique_ptr
}

void VertexBuffer::bind() const {
    glBindBuffer(GL_ARRAY_BUFFER, m_RenderID);
}

void VertexBuffer::unBind() const{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

VertexBuffer::~VertexBuffer(){
    glDeleteBuffers(1, &m_RenderID);
}